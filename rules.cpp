#include <cassert>

#include "rules.h"
#include "utils.h"

std::vector<Move> get_valid_bishop_moves(Board *board, int i, int j) {
    std::vector<Move> move_list;

    int color = get_piece(board, i, j) % 2;

    for (int ii = 1; ii < 8; ii++) {
        int new_i = i+ii;
        int new_j = j+ii;
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            if (board->pos[new_i][new_j] == EMPTY || get_piece(board, new_i, new_j) % 2 != color) {
                Move move = {
                        { (uint8_t) i, (uint8_t) j },
                        { (uint8_t) new_i, (uint8_t) new_j }
                };
                move_list.push_back(move);
            }
            if (get_piece(board, new_i, new_j) != EMPTY) {
                break;
            }
        }
    }

    for (int ii = 1; ii < 8; ii++) {
        int new_i = i+ii;
        int new_j = j-ii;
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            if (get_piece(board, new_i, new_j) == EMPTY || get_piece(board, new_i, new_j) % 2 != color) {
                Move move = {
                        { (uint8_t) i, (uint8_t) j },
                        { (uint8_t) new_i, (uint8_t) new_j }
                };
                move_list.push_back(move);
            }
            if (get_piece(board, new_i, new_j) != EMPTY) {
                break;
            }
        }
    }

    for (int ii = 1; ii < 8; ii++) {
        int new_i = i-ii;
        int new_j = j-ii;
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            if (get_piece(board, new_i, new_j) == EMPTY || get_piece(board, new_i, new_j) % 2 != color) {
                Move move = {
                        { (uint8_t) i, (uint8_t) j },
                        { (uint8_t) new_i, (uint8_t) new_j }
                };
                move_list.push_back(move);
            }
            if (get_piece(board, new_i, new_j) != EMPTY) {
                break;
            }
        }
    }

    for (int ii = 1; ii < 8; ii++) {
        int new_i = i-ii;
        int new_j = j+ii;
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            if (get_piece(board, new_i, new_j) == EMPTY || get_piece(board, new_i, new_j) % 2 != color) {
                Move move = {
                        { (uint8_t) i, (uint8_t) j },
                        { (uint8_t) new_i, (uint8_t) new_j }
                };
                move_list.push_back(move);
            }
            if (get_piece(board, new_i, new_j) != EMPTY) {
                break;
            }
        }
    }

    return move_list;
}

std::vector<Move> get_valid_knight_moves(Board *board, int i, int j) {
    std::vector<Move> move_list;

    int color = get_piece(board, i, j) % 2;

    int new_i = i+1; int new_j = j+2;
    if (is_inside_board(board, new_i, new_j) && (get_piece(board, new_i, new_j) == EMPTY || get_piece(board, new_i, new_j) % 2 != color))
        move_list.push_back(Move{ { (uint8_t) i, (uint8_t) j }, { (uint8_t) new_i, (uint8_t) new_j } });

    new_i = i+1; new_j = j-2;
    if (is_inside_board(board, new_i, new_j) && (get_piece(board, new_i, new_j) == EMPTY || get_piece(board, new_i, new_j) % 2 != color))
        move_list.push_back(Move{ { (uint8_t) i, (uint8_t) j }, { (uint8_t) new_i, (uint8_t) new_j } });

    new_i = i+2; new_j = j+1;
    if (is_inside_board(board, new_i, new_j) && (get_piece(board, new_i, new_j) == EMPTY || get_piece(board, new_i, new_j) % 2 != color))
        move_list.push_back(Move{ { (uint8_t) i, (uint8_t) j }, { (uint8_t) new_i, (uint8_t) new_j } });

    new_i = i+2; new_j = j-1;
    if (is_inside_board(board, new_i, new_j) && (get_piece(board, new_i, new_j) == EMPTY || get_piece(board, new_i, new_j) % 2 != color))
        move_list.push_back(Move{ { (uint8_t) i, (uint8_t) j }, { (uint8_t) new_i, (uint8_t) new_j } });

    new_i = i-2; new_j = j+1;
    if (is_inside_board(board, new_i, new_j) && (get_piece(board, new_i, new_j) == EMPTY || get_piece(board, new_i, new_j) % 2 != color))
        move_list.push_back(Move{ { (uint8_t) i, (uint8_t) j }, { (uint8_t) new_i, (uint8_t) new_j } });

    new_i = i-2; new_j = j-1;
    if (is_inside_board(board, new_i, new_j) && (get_piece(board, new_i, new_j) == EMPTY || get_piece(board, new_i, new_j) % 2 != color))
        move_list.push_back(Move{ { (uint8_t) i, (uint8_t) j }, { (uint8_t) new_i, (uint8_t) new_j } });

    new_i = i-1; new_j = j+2;
    if (is_inside_board(board, new_i, new_j) && (get_piece(board, new_i, new_j) == EMPTY || get_piece(board, new_i, new_j) % 2 != color))
        move_list.push_back(Move{ { (uint8_t) i, (uint8_t) j }, { (uint8_t) new_i, (uint8_t) new_j } });

    new_i = i-1; new_j = j-2;
    if (is_inside_board(board, new_i, new_j) && (get_piece(board, new_i, new_j) == EMPTY || get_piece(board, new_i, new_j) % 2 != color))
        move_list.push_back(Move{ { (uint8_t) i, (uint8_t) j }, { (uint8_t) new_i, (uint8_t) new_j } });

    return move_list;
}

std::vector<Move> get_valid_rook_moves(Board *board, int i, int j) {
    std::vector<Move> move_list;

    int color = get_piece(board, i, j) % 2;

    for (int ii = 1; ii < 8; ii++) {
        int new_i = i+ii;
        int new_j = j;
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            if (get_piece(board, new_i, new_j) == EMPTY || get_piece(board, new_i, new_j) % 2 != color) {
                Move move = {
                        { (uint8_t) i, (uint8_t) j },
                        { (uint8_t) new_i, (uint8_t) new_j }
                };
                move_list.push_back(move);
            }
            if (get_piece(board, new_i, new_j) != EMPTY) {
                break;
            }
        }
    }

    for (int ii = 1; ii < 8; ii++) {
        int new_i = i-ii;
        int new_j = j;
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            if (get_piece(board, new_i, new_j) == EMPTY || get_piece(board, new_i, new_j) % 2 != color) {
                Move move = {
                        { (uint8_t) i, (uint8_t) j },
                        { (uint8_t) new_i, (uint8_t) new_j }
                };
                move_list.push_back(move);
            }
            if (get_piece(board, new_i, new_j) != EMPTY) {
                break;
            }
        }
    }

    for (int ii = 1; ii < 8; ii++) {
        int new_i = i;
        int new_j = j+ii;
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            if (get_piece(board, new_i, new_j) == EMPTY || get_piece(board, new_i, new_j) % 2 != color) {
                Move move = {
                        { (uint8_t) i, (uint8_t) j },
                        { (uint8_t) new_i, (uint8_t) new_j }
                };
                move_list.push_back(move);
            }
            if (get_piece(board, new_i, new_j) != EMPTY) {
                break;
            }
        }
    }

    for (int ii = 1; ii < 8; ii++) {
        int new_i = i;
        int new_j = j-ii;
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            if (get_piece(board, new_i, new_j) == EMPTY || get_piece(board, new_i, new_j) % 2 != color) {
                Move move = {
                        { (uint8_t) i, (uint8_t) j },
                        { (uint8_t) new_i, (uint8_t) new_j }
                };
                move_list.push_back(move);
            }
            if (get_piece(board, new_i, new_j) != EMPTY) {
                break;
            }
        }
    }

    return move_list;
}

std::vector<Move> get_valid_queen_moves(Board *board, int i, int j) {
    std::vector<Move> move_list;
    move_list = get_valid_bishop_moves(board, i, j);
    std::vector<Move> tmp_list = get_valid_rook_moves(board, i, j);
    move_list.insert(move_list.end(), tmp_list.begin(), tmp_list.end());
    return move_list;
}

std::vector<Move> get_valid_pawn_moves(Board *board, int i, int j) {
    std::vector<Move> move_list;

    int color = get_piece(board, i, j) % 2;

    if (color == 1) { // white
        int new_i = i-1;
        int new_j = j;
        if (get_piece(board, new_i, new_j) == EMPTY) {
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) new_i, (uint8_t) new_j }
            };
            move_list.push_back(move);
        }

        if (i == 6 && get_piece(board, new_i, new_j) == EMPTY) {
            new_i = i-2;
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) new_i, (uint8_t) new_j }
            };
            move_list.push_back(move);
        }

        new_i = i-1;
        new_j = j-1;
        if (has_piece(board, new_i, new_j) && get_piece(board, new_i, new_j) % 2 != color) {
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) new_i, (uint8_t) new_j }
            };
            move_list.push_back(move);
        }

        new_i = i-1;
        new_j = j+1;
        if (has_piece(board, new_i, new_j) && get_piece(board, new_i, new_j) % 2 != color) {
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) new_i, (uint8_t) new_j }
            };
            move_list.push_back(move);
        }

        // en passant to the left
        if (board->last_move.from[0] == i-2 && board->last_move.from[1] == j-1 &&
            board->last_move.to[0] == i && board->last_move.to[1] == j-1) {
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) (i-1), (uint8_t) (j-1) }
            };
            move_list.push_back(move);
        }

        // en passant to the right
        if (board->last_move.from[0] == i-2 && board->last_move.from[1] == j+1 &&
            board->last_move.to[0] == i && board->last_move.to[1] == j+1) {
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) (i-1), (uint8_t) (j+1) }
            };
            move_list.push_back(move);
        }
    } else { // black
        int new_i = i+1;
        int new_j = j;
        if (get_piece(board, new_i, new_j) == EMPTY) {
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) new_i, (uint8_t) new_j }
            };
            move_list.push_back(move);
        }

        if (i == 1 && get_piece(board, new_i, new_j) == EMPTY) {
            new_i = i+2;
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) new_i, (uint8_t) new_j }
            };
            move_list.push_back(move);
        }

        new_i = i+1;
        new_j = j-1;
        if (has_piece(board, new_i, new_j) && get_piece(board, new_i, new_j) % 2 != color) {
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) new_i, (uint8_t) new_j }
            };
            move_list.push_back(move);
        }

        new_i = i+1;
        new_j = j+1;
        if (has_piece(board, new_i, new_j) && get_piece(board, new_i, new_j) % 2 != color) {
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) new_i, (uint8_t) new_j }
            };
            move_list.push_back(move);
        }

        // en passant to the left
        if (board->last_move.from[0] == i+2 && board->last_move.from[1] == j-1 &&
            board->last_move.to[0] == i && board->last_move.to[1] == j-1) {
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) (i+1), (uint8_t) (j-1) }
            };
            move_list.push_back(move);
        }

        // en passant to the right
        if (board->last_move.from[0] == i+2 && board->last_move.from[1] == j+1 &&
            board->last_move.to[0] == i && board->last_move.to[1] == j+1) {
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) (i+1), (uint8_t) (j+1) }
            };
            move_list.push_back(move);
        }
    }

    return move_list;
}

std::vector<Move> get_valid_king_moves(Board *board, int i, int j) {
    std::vector<Move> move_list;

    int color = get_piece(board, i, j) % 2;

    for (int ii = -1; ii <= 1; ii++) {
        for (int jj = -1; jj <= 1; jj++) {
            int new_i = i+ii; int new_j = j+jj;
            if (is_inside_board(board, new_i, new_j) && (get_piece(board, new_i, new_j) == EMPTY || get_piece(board, new_i, new_j) % 2 != color))
                move_list.push_back(Move{ { (uint8_t) i, (uint8_t) j }, { (uint8_t) new_i, (uint8_t) new_j } });
        }
    }

    return move_list;
}

// Note: Not all of these moves are valid, does not take into account moves that would put the player in check.
static std::vector<Move> get_player_unsafe_attacks(Board *board, int color) {
    std::vector<Move> attacks;
    for (int ii = 0; ii < 8; ii++) {
        for (int jj = 0; jj < 8; jj++) {
            if (has_piece(board, ii, jj) && get_piece(board, ii, jj) % 2 == color) {
                std::vector<Move> tmp_list = get_valid_moves_from(board, ii, jj);
                attacks.insert(attacks.begin(), tmp_list.begin(), tmp_list.end());
            }
        }
    }

    return attacks;
}

std::vector<Move> get_valid_moves_from(Board *board, int i, int j) {
    assert(has_piece(board, i, j));

    ChessPiece piece = get_piece(board, i, j);

    std::vector<Move> list;

    switch (piece) {
        case EMPTY:
            break;
        case WHITE_BISHOP:
        case BLACK_BISHOP:
            list = get_valid_bishop_moves(board, i, j);
            break;
        case WHITE_KNIGHT:
        case BLACK_KNIGHT:
            list = get_valid_knight_moves(board, i, j);
            break;
        case WHITE_ROOK:
        case BLACK_ROOK:
            list = get_valid_rook_moves(board, i, j);
            break;
        case WHITE_PAWN:
        case BLACK_PAWN:
            list = get_valid_pawn_moves(board, i, j);
            break;
        case WHITE_QUEEN:
        case BLACK_QUEEN:
            list = get_valid_queen_moves(board, i, j);
            break;
        case WHITE_KING:
        case BLACK_KING:
            list = get_valid_king_moves(board, i, j);
            break;
        default:
            unreachable("Invalid piece!");
            break;
    }

    return list;
}

bool would_be_in_check(Board *board, int color, Move move) {
    Board b;
    memcpy(&b, board, sizeof(b));

    play_move(&b, move);

    return is_in_check(&b, color);
}

// TODO: force player to prevent check
std::vector<Move> get_valid_moves(Board *board, int color) {
    std::vector<Move> move_list;

    for (int ii = 0; ii < 8; ii++) {
        for (int jj = 0; jj < 8; jj++) {
            if (get_piece(board, ii, jj) == EMPTY || get_piece(board, ii, jj) % 2 != color)
                continue;

            std::vector<Move> tmp_moves = get_valid_moves_from(board, ii, jj);

            for (auto & move : tmp_moves) {
                if (would_be_in_check(board, color, move))
                    continue;

                move_list.push_back(move);
            }
        }
    }

    return move_list;
}

void get_king_pos(Board *board, int color, int *king_i, int *king_j) {
    for (int ii = 0; ii < 8; ii++) {
        for (int jj = 0; jj < 8; jj++) {
            if (get_piece(board, ii, jj) == BLACK_KING - color) {
                *king_i = ii;
                *king_j = jj;
                return;
            }
        }
    }

    unreachable("King not found inside the board!");
}

void play_move(Board *board, Move move) {
    //printf("Player %d plays: %c%d-%c%d\n", turn_color(board), 'h'-move.from[0], 7-move.from[1], 'h'-move.to[0], 7-move.to[1]);
    board->pos[move.to[0]][move.to[1]] = board->pos[move.from[0]][move.from[1]];
    board->pos[move.from[0]][move.from[1]] = EMPTY;

    board->last_move = move;
}

bool is_in_check(Board *board, int color) {
    int king_i = 0, king_j = 0;
    get_king_pos(board, color, &king_i, &king_j);

    std::vector<Move> adv_attacks = get_player_unsafe_attacks(board, (color + 1) % 2);

    for (auto & adv_attack : adv_attacks) {
        if (adv_attack.to[0] == king_i && adv_attack.to[1] == king_j) {
            return true;
        }
    }

    return false;
}

bool is_mated(Board *board, int color) {
    if (!is_in_check(board, color))
        return false;

    std::vector<Move> move_list = get_valid_moves(board, 1);

    for (auto & move : move_list) {
        if (!would_be_in_check(board, color, move)) {
            return false;
        }
    }

    return true;
}

GameResult get_game_status(Board *board) {
    if (is_mated(board, 0))
        return RESULT_WHITE_WON;

    if (is_mated(board, 1))
        return RESULT_BLACK_WON;

    if (get_valid_moves(board, turn_color(board)).size() == 0)
        return RESULT_DRAW;

    return RESULT_UNFINISHED;
}

void print_game_result(GameResult result) {
    switch (result) {
        case RESULT_WHITE_WON:
            puts("White won!");
            break;
        case RESULT_BLACK_WON:
            puts("Black won!");
            break;
        case RESULT_DRAW:
            puts("Draw!");
            break;
        default:
            break;
    }
}