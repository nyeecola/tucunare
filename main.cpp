#include <iostream>
#include <cstdint>
#include <cstring>
#include <cstdio>
#include <vector>

enum ChessPiece {
    EMPTY,
    WHITE_PAWN,
    BLACK_PAWN,
    WHITE_KNIGHT,
    BLACK_KNIGHT,
    WHITE_BISHOP,
    BLACK_BISHOP,
    WHITE_ROOK,
    BLACK_ROOK,
    WHITE_QUEEN,
    BLACK_QUEEN,
    WHITE_KING,
    BLACK_KING,

    MAX_PIECES
};

struct Move {
    uint8_t from[2];
    uint8_t to[2];
};

inline bool is_white(ChessPiece c) { return c > 0 && c < MAX_PIECES && c % 2 == 0; };
inline bool is_black(ChessPiece c) { return c > 0 && c < MAX_PIECES && c % 2 == 1; };

ChessPiece global_board[8][8];

void unreachable(char *str) {
    fprintf(stderr, "Unreachable: %s\n", str);
    exit(1);
}

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

    return is_black(c) ? r += ('A' - 'a') : r;
}

void draw_board() {
    for (int i = 7; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            printf("%c ", char_representation(global_board[i][j]));
        }
        printf("\n");
    }
}

void initialize_board() {
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

    memcpy(global_board, starting_pos, sizeof(global_board));
}

std::vector<Move> get_valid_bishop_moves(int x, int y) {
    std::vector<Move> move_list;

    bool is_white = global_board[x][y] % 2;

    for (int i = 1; i < 7; i++) {
        int new_x = x+i;
        int new_y = y+i;
        if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8) {
            if (global_board[new_x][new_y] == EMPTY || global_board[new_x][new_y] % 2 != is_white) {
                Move move = {
                    { (uint8_t) x, (uint8_t) y },
                    { (uint8_t) new_x, (uint8_t) new_y }
                };
                move_list.push_back(move);
            } else {
                break;
            }
        }
    }

    for (int i = 1; i < 7; i++) {
        int new_x = x+i;
        int new_y = y-i;
        if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8) {
            if (global_board[new_x][new_y] == EMPTY || global_board[new_x][new_y] % 2 != is_white) {
                Move move = {
                    { (uint8_t) x, (uint8_t) y },
                    { (uint8_t) new_x, (uint8_t) new_y }
                };
                move_list.push_back(move);
            } else {
                break;
            }
        }
    }

    for (int i = 1; i < 7; i++) {
        int new_x = x-i;
        int new_y = y-i;
        if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8) {
            if (global_board[new_x][new_y] == EMPTY || global_board[new_x][new_y] % 2 != is_white) {
                Move move = {
                    { (uint8_t) x, (uint8_t) y },
                    { (uint8_t) new_x, (uint8_t) new_y }
                };
                move_list.push_back(move);
            } else {
                break;
            }
        }
    }

    for (int i = 1; i < 7; i++) {
        int new_x = x-i;
        int new_y = y+i;
        if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8) {
            if (global_board[new_x][new_y] == EMPTY || global_board[new_x][new_y] % 2 != is_white) {
                Move move = {
                    { (uint8_t) x, (uint8_t) y },
                    { (uint8_t) new_x, (uint8_t) new_y }
                };
                move_list.push_back(move);
            } else {
                break;
            }
        }
    }

    return move_list;
}

std::vector<Move> get_valid_moves_from(int x, int y) {
    ChessPiece piece = global_board[x][y];

    std::vector<Move> list;

    switch (piece) {
        case EMPTY:
            break;
        case WHITE_BISHOP:
        case BLACK_BISHOP:
            list = get_valid_bishop_moves(x, y);
            break;
        case WHITE_KNIGHT:
        case BLACK_KNIGHT:
            //list = get_valid_knight_moves(x, y);
            break;
        case WHITE_ROOK:
        case BLACK_ROOK:
            //list = get_valid_rook_moves(x, y);
            break;
        case WHITE_PAWN:
        case BLACK_PAWN:
            //list = get_valid_pawn_moves(x, y);
            break;
        case WHITE_QUEEN:
        case BLACK_QUEEN:
            //list = get_valid_queen_moves(x, y);
            break;
        case WHITE_KING:
        case BLACK_KING:
            //list = get_valid_king_moves(x, y);
            break;
        default:
            unreachable("Invalid piece!");
            break;
    }

    return list;
}

std::vector<Move> get_valid_moves() {
    std::vector<Move> move_list;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::vector<Move> tmp_moves = get_valid_moves_from(i, j);

            move_list.insert(move_list.end(), tmp_moves.begin(), tmp_moves.end());
        }
    }

    return move_list;
}

int main() {
    initialize_board();
    draw_board();

    return 0;
}
