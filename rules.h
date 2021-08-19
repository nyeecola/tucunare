#ifndef TUCUNARE_RULES_H
#define TUCUNARE_RULES_H

#include <cstdint>
#include <vector>

enum GameResult {
    RESULT_UNFINISHED,
    RESULT_WHITE_WON,
    RESULT_BLACK_WON,
    RESULT_DRAW
};

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

struct Board {
    ChessPiece pos[8][8];
    char castling_rights; // 0b0000XXXX
    Move last_move;
};

inline bool is_white(ChessPiece c) { return c > 0 && c < MAX_PIECES && c % 2 == 0; }
inline bool is_black(ChessPiece c) { return c > 0 && c < MAX_PIECES && c % 2 == 1; }
inline int turn_color(Board *board) { return (board->pos[board->last_move.to[0]][board->last_move.to[1]] + 1) % 2; }

inline bool is_inside_board(Board *board, int x, int y) { return (x >= 0 && x < 8 && y >= 0 && y < 8); }

std::vector<Move> get_valid_bishop_moves(Board *board, int x, int y);
std::vector<Move> get_valid_moves_from(Board *board, int x, int y);
std::vector<Move> get_valid_moves(Board *board, int color);

bool is_in_check(Board *board, int color);
bool is_mated(Board *board, int color);

void play_move(Board *board, Move move);

GameResult get_game_status(Board *board);
void print_game_result(GameResult result);

#endif //TUCUNARE_RULES_H
