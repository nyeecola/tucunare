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

std::vector<Move> get_valid_king_moves(Board *board, int i, int j, bool recurse) {
    std::vector<Move> king_moves = get_valid_king_moves_helper(board, i, j);

    if (recurse) {
        std::vector<Move> king_danger;
        for (int ii = 0; ii < 8; ii++) {
            for (int jj = 0; jj < 8; jj++) {
                if (board->pos[i][j] != EMPTY && board->pos[ii][jj] % 2 == board->pos[i][j] % 2) {
                    std::vector<Move> tmp_list = get_valid_moves_from(board, ii, jj, false);
                    king_danger.insert(king_danger.begin(), tmp_list.begin(), tmp_list.end());
                    for (int ll = 0; ll < king_moves.size(); ll++) {
                        for (int kk = 0; kk < king_danger.size(); kk++) {
                            if (king_danger[kk].to[0] == king_moves[ll].to[0] && king_danger[kk].to[1] == king_moves[ll].to[1]) {
                                king_moves.erase(king_moves.begin()+ll);
                                ll--;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    return king_moves;
}

std::vector<Move> get_valid_moves_from(Board *board, int i, int j, bool recurse) {
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

// TODO: force player to prevent check
std::vector<Move> get_valid_moves(Board *board, int color) {
    std::vector<Move> move_list;

    for (int ii = 0; ii < 8; ii++) {
        for (int jj = 0; jj < 8; jj++) {
            if (board->pos[ii][jj] == EMPTY || board->pos[ii][jj] % 2 != color)
                continue;

            std::vector<Move> tmp_moves = get_valid_moves_from(board, ii, jj);

            move_list.insert(move_list.end(), tmp_moves.begin(), tmp_moves.end());
        }
    }

    return move_list;
}

void play_move(Board *board, Move move) {
    board->pos[move.to[0]][move.to[1]] = board->pos[move.from[0]][move.from[1]];
    board->pos[move.from[0]][move.from[1]] = EMPTY;
}
