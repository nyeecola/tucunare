#include <cassert>

#include "rules.h"
#include "utils.h"

std::vector<Move> get_valid_bishop_moves(Board *board, int i, int j) {
    std::vector<Move> move_list;

    int color = board->pos[i][j] % 2;

    for (int ii = 1; ii < 8; ii++) {
        int new_i = i+ii;
        int new_j = j+ii;
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            if (board->pos[new_i][new_j] == EMPTY || board->pos[new_i][new_j] % 2 != color) {
                Move move = {
                        { (uint8_t) i, (uint8_t) j },
                        { (uint8_t) new_i, (uint8_t) new_j }
                };
                move_list.push_back(move);
            }
            if (board->pos[new_i][new_j] != EMPTY) {
                break;
            }
        }
    }

    for (int ii = 1; ii < 8; ii++) {
        int new_i = i+ii;
        int new_j = j-ii;
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            if (board->pos[new_i][new_j] == EMPTY || board->pos[new_i][new_j] % 2 != color) {
                Move move = {
                        { (uint8_t) i, (uint8_t) j },
                        { (uint8_t) new_i, (uint8_t) new_j }
                };
                move_list.push_back(move);
            }
            if (board->pos[new_i][new_j] != EMPTY) {
                break;
            }
        }
    }

    for (int ii = 1; ii < 8; ii++) {
        int new_i = i-ii;
        int new_j = j-ii;
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            if (board->pos[new_i][new_j] == EMPTY || board->pos[new_i][new_j] % 2 != color) {
                Move move = {
                        { (uint8_t) i, (uint8_t) j },
                        { (uint8_t) new_i, (uint8_t) new_j }
                };
                move_list.push_back(move);
            }
            if (board->pos[new_i][new_j] != EMPTY) {
                break;
            }
        }
    }

    for (int ii = 1; ii < 8; ii++) {
        int new_i = i-ii;
        int new_j = j+ii;
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            if (board->pos[new_i][new_j] == EMPTY || board->pos[new_i][new_j] % 2 != color) {
                Move move = {
                        { (uint8_t) i, (uint8_t) j },
                        { (uint8_t) new_i, (uint8_t) new_j }
                };
                move_list.push_back(move);
            }
            if (board->pos[new_i][new_j] != EMPTY) {
                break;
            }
        }
    }

    return move_list;
}

std::vector<Move> get_valid_knight_moves(Board *board, int i, int j) {
    std::vector<Move> move_list;

    int color = board->pos[i][j] % 2;

    int new_i = i+1; int new_j = j+2;
    if (is_inside_board(board, new_i, new_j) && (board->pos[new_i][new_j] == EMPTY || board->pos[new_i][new_j] % 2 != color))
        move_list.push_back(Move{ { (uint8_t) i, (uint8_t) j }, { (uint8_t) new_i, (uint8_t) new_j } });

    new_i = i+1; new_j = j-2;
    if (is_inside_board(board, new_i, new_j) && (board->pos[new_i][new_j] == EMPTY || board->pos[new_i][new_j] % 2 != color))
        move_list.push_back(Move{ { (uint8_t) i, (uint8_t) j }, { (uint8_t) new_i, (uint8_t) new_j } });

    new_i = i+2; new_j = j+1;
    if (is_inside_board(board, new_i, new_j) && (board->pos[new_i][new_j] == EMPTY || board->pos[new_i][new_j] % 2 != color))
        move_list.push_back(Move{ { (uint8_t) i, (uint8_t) j }, { (uint8_t) new_i, (uint8_t) new_j } });

    new_i = i+2; new_j = j-1;
    if (is_inside_board(board, new_i, new_j) && (board->pos[new_i][new_j] == EMPTY || board->pos[new_i][new_j] % 2 != color))
        move_list.push_back(Move{ { (uint8_t) i, (uint8_t) j }, { (uint8_t) new_i, (uint8_t) new_j } });

    new_i = i-2; new_j = j+1;
    if (is_inside_board(board, new_i, new_j) && (board->pos[new_i][new_j] == EMPTY || board->pos[new_i][new_j] % 2 != color))
        move_list.push_back(Move{ { (uint8_t) i, (uint8_t) j }, { (uint8_t) new_i, (uint8_t) new_j } });

    new_i = i-2; new_j = j-1;
    if (is_inside_board(board, new_i, new_j) && (board->pos[new_i][new_j] == EMPTY || board->pos[new_i][new_j] % 2 != color))
        move_list.push_back(Move{ { (uint8_t) i, (uint8_t) j }, { (uint8_t) new_i, (uint8_t) new_j } });

    new_i = i-1; new_j = j+2;
    if (is_inside_board(board, new_i, new_j) && (board->pos[new_i][new_j] == EMPTY || board->pos[new_i][new_j] % 2 != color))
        move_list.push_back(Move{ { (uint8_t) i, (uint8_t) j }, { (uint8_t) new_i, (uint8_t) new_j } });

    new_i = i-1; new_j = j-2;
    if (is_inside_board(board, new_i, new_j) && (board->pos[new_i][new_j] == EMPTY || board->pos[new_i][new_j] % 2 != color))
        move_list.push_back(Move{ { (uint8_t) i, (uint8_t) j }, { (uint8_t) new_i, (uint8_t) new_j } });

    return move_list;
}

std::vector<Move> get_valid_rook_moves(Board *board, int i, int j) {
    std::vector<Move> move_list;

    int color = board->pos[i][j] % 2;

    for (int ii = 1; ii < 8; ii++) {
        int new_i = i+ii;
        int new_j = j;
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            if (board->pos[new_i][new_j] == EMPTY || board->pos[new_i][new_j] % 2 != color) {
                Move move = {
                        { (uint8_t) i, (uint8_t) j },
                        { (uint8_t) new_i, (uint8_t) new_j }
                };
                move_list.push_back(move);
            }
            if (board->pos[new_i][new_j] != EMPTY) {
                break;
            }
        }
    }

    for (int ii = 1; ii < 8; ii++) {
        int new_i = i-ii;
        int new_j = j;
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            if (board->pos[new_i][new_j] == EMPTY || board->pos[new_i][new_j] % 2 != color) {
                Move move = {
                        { (uint8_t) i, (uint8_t) j },
                        { (uint8_t) new_i, (uint8_t) new_j }
                };
                move_list.push_back(move);
            }
            if (board->pos[new_i][new_j] != EMPTY) {
                break;
            }
        }
    }

    for (int ii = 1; ii < 8; ii++) {
        int new_i = i;
        int new_j = j+ii;
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            if (board->pos[new_i][new_j] == EMPTY || board->pos[new_i][new_j] % 2 != color) {
                Move move = {
                        { (uint8_t) i, (uint8_t) j },
                        { (uint8_t) new_i, (uint8_t) new_j }
                };
                move_list.push_back(move);
            }
            if (board->pos[new_i][new_j] != EMPTY) {
                break;
            }
        }
    }

    for (int ii = 1; ii < 8; ii++) {
        int new_i = i;
        int new_j = j-ii;
        if (new_i >= 0 && new_i < 8 && new_j >= 0 && new_j < 8) {
            if (board->pos[new_i][new_j] == EMPTY || board->pos[new_i][new_j] % 2 != color) {
                Move move = {
                        { (uint8_t) i, (uint8_t) j },
                        { (uint8_t) new_i, (uint8_t) new_j }
                };
                move_list.push_back(move);
            }
            if (board->pos[new_i][new_j] != EMPTY) {
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

    int color = board->pos[i][j] % 2;

    if (color == 1) { // white
        int new_i = i-1;
        int new_j = j;
        if (board->pos[new_i][new_j] == EMPTY) {
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) new_i, (uint8_t) new_j }
            };
            move_list.push_back(move);
        }

        if (i == 6 && board->pos[new_i][new_j] == EMPTY) {
            new_i = i-2;
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) new_i, (uint8_t) new_j }
            };
            move_list.push_back(move);
        }

        new_i = i-1;
        new_j = j-1;
        if (board->pos[new_i][new_j] != EMPTY && board->pos[new_i][new_j] % 2 != color) {
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) new_i, (uint8_t) new_j }
            };
            move_list.push_back(move);
        }

        new_i = i-1;
        new_j = j+1;
        if (board->pos[new_i][new_j] != EMPTY && board->pos[new_i][new_j] % 2 != color) {
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
        if (board->pos[new_i][new_j] == EMPTY) {
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) new_i, (uint8_t) new_j }
            };
            move_list.push_back(move);
        }

        if (i == 1 && board->pos[new_i][new_j] == EMPTY) {
            new_i = i+2;
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) new_i, (uint8_t) new_j }
            };
            move_list.push_back(move);
        }

        new_i = i+1;
        new_j = j-1;
        if (board->pos[new_i][new_j] != EMPTY && board->pos[new_i][new_j] % 2 != color) {
            Move move = {
                    { (uint8_t) i, (uint8_t) j },
                    { (uint8_t) new_i, (uint8_t) new_j }
            };
            move_list.push_back(move);
        }

        new_i = i+1;
        new_j = j+1;
        if (board->pos[new_i][new_j] != EMPTY && board->pos[new_i][new_j] % 2 != color) {
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

std::vector<Move> get_valid_king_moves_helper(Board *board, int i, int j) {
    std::vector<Move> move_list;

    int color = board->pos[i][j] % 2;

    for (int ii = -1; ii <= 1; ii++) {
        for (int jj = -1; jj <= 1; jj++) {
            int new_i = i+ii; int new_j = j+jj;
            if (is_inside_board(board, new_i, new_j) && (board->pos[new_i][new_j] == EMPTY || board->pos[new_i][new_j] % 2 != color))
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
            if (board->pos[ii][jj] != EMPTY && board->pos[ii][jj] % 2 == color) {
                std::vector<Move> tmp_list = get_valid_moves_from(board, ii, jj, false);
                attacks.insert(attacks.begin(), tmp_list.begin(), tmp_list.end());
            }
        }
    }

    return attacks;
}

std::vector<Move> get_valid_king_moves(Board *board, int i, int j, bool recurse) {
    std::vector<Move> king_moves = get_valid_king_moves_helper(board, i, j);

    if (recurse) {
        std::vector<Move> adv_attacks = get_player_unsafe_attacks(board, (board->pos[i][j] + 1) % 2);

        for (int ll = 0; ll < king_moves.size(); ll++) {
            for (int kk = 0; kk < adv_attacks.size(); kk++) {
                if (adv_attacks[kk].to[0] == king_moves[ll].to[0] && adv_attacks[kk].to[1] == king_moves[ll].to[1]) {
                    king_moves.erase(king_moves.begin()+ll);
                    ll--;
                    break;
                }
            }
        }
    }

    return king_moves;
}

std::vector<Move> get_valid_moves_from(Board *board, int i, int j, bool recurse) {
    assert(board->pos[i][j] != EMPTY);

    ChessPiece piece = board->pos[i][j];

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
            list = get_valid_king_moves(board, i, j, recurse);
            break;
        default:
            unreachable("Invalid piece!");
            break;
    }

    return list;
}

bool would_remain_in_check(Board *board, int color, Move move) {
    Board b;
    memcpy(&b, board, sizeof(b));

    play_move(&b, move);

    return is_in_check(&b, color);
}

// TODO: force player to prevent check
std::vector<Move> get_valid_moves(Board *board, int color) {
    std::vector<Move> move_list;

    bool in_check = is_in_check(board, color);

    for (int ii = 0; ii < 8; ii++) {
        for (int jj = 0; jj < 8; jj++) {
            if (board->pos[ii][jj] == EMPTY || board->pos[ii][jj] % 2 != color)
                continue;

            std::vector<Move> tmp_moves = get_valid_moves_from(board, ii, jj);

            for (auto & move : tmp_moves) {
                if (in_check && would_remain_in_check(board, color, move))
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
            if (board->pos[ii][jj] == BLACK_KING - color) {
                *king_i = ii;
                *king_j = jj;
                return;
            }
        }
    }

    unreachable("King not found inside the board!");
}

void play_move(Board *board, Move move) {
    board->pos[move.to[0]][move.to[1]] = board->pos[move.from[0]][move.from[1]];
    board->pos[move.from[0]][move.from[1]] = EMPTY;
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
        if (!would_remain_in_check(board, color, move)) {
            return false;
        }
    }

    return true;
}
