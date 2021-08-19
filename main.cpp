#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <vector>
#include <random>
#include <chrono>
#include <thread>

#include "rules.h"
#include "utils.h"

char char_representation(ChessPiece c) {
    char r = ' ';
    switch (c) {
        case EMPTY:
            r = '.';
            break;
        case WHITE_BISHOP:
        case BLACK_BISHOP:
            r = 'b';
            break;
        case WHITE_KNIGHT:
        case BLACK_KNIGHT:
            r = 'n';
            break;
        case WHITE_ROOK:
        case BLACK_ROOK:
            r = 'r';
            break;
        case WHITE_PAWN:
        case BLACK_PAWN:
            r = 'p';
            break;
        case WHITE_QUEEN:
        case BLACK_QUEEN:
            r = 'q';
            break;
        case WHITE_KING:
        case BLACK_KING:
            r = 'k';
            break;
        default:
            unreachable("Invalid piece!");
            break;
    }

    return is_black(c) ? r + ('A' - 'a') : r;
}

void draw_board(Board *board) {
    puts(" ");
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", char_representation(board->pos[i][j]));
        }
        printf("\n");
    }
}

void initialize_board(Board *board) {
    ChessPiece starting_pos[8][8] = {
            { BLACK_ROOK, BLACK_KNIGHT, BLACK_BISHOP, BLACK_QUEEN, BLACK_KING, BLACK_BISHOP, BLACK_KNIGHT, BLACK_ROOK },
            { BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN, BLACK_PAWN },
            { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
            { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
            { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
            { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
            { WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN, WHITE_PAWN },
            { WHITE_ROOK, WHITE_KNIGHT, WHITE_BISHOP, WHITE_QUEEN, WHITE_KING, WHITE_BISHOP, WHITE_KNIGHT, WHITE_ROOK },
    };

    memcpy(&board->pos[0][0], starting_pos, sizeof(starting_pos));
}

int main() {
    std::srand(std::time(nullptr));

    Board board = {};

    initialize_board(&board);

    // main loop
    while (true) {
        // AI-1 move
        std::vector<Move> move_list = get_valid_moves(&board, 1);
        play_move(&board, move_list[std::rand() % move_list.size()]);
        assert(!is_in_check(&board, 1));
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        GameResult res = get_game_status(&board);
        if (res != RESULT_UNFINISHED) {
            print_game_result(res);
        }

        // render
        draw_board(&board);

        // AI-2 move
        move_list = get_valid_moves(&board, 0);
        play_move(&board, move_list[std::rand() % move_list.size()]);
        assert(!is_in_check(&board, 0));
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        res = get_game_status(&board);
        if (res != RESULT_UNFINISHED) {
            print_game_result(res);
        }

        // render
        draw_board(&board);
    }

    return 0;
}
