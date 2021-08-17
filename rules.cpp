#include "rules.h"
#include "utils.h"

std::vector<Move> get_valid_bishop_moves(Board *board, int x, int y) {
    std::vector<Move> move_list;

    int is_white = board->pos[x][y] % 2;

    for (int i = 1; i < 7; i++) {
        int new_x = x+i;
        int new_y = y+i;
        if (new_x >= 0 && new_x < 8 && new_y >= 0 && new_y < 8) {
            if (board->pos[new_x][new_y] == EMPTY || board->pos[new_x][new_y] % 2 != is_white) {
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
            if (board->pos[new_x][new_y] == EMPTY || board->pos[new_x][new_y] % 2 != is_white) {
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
            if (board->pos[new_x][new_y] == EMPTY || board->pos[new_x][new_y] % 2 != is_white) {
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
            if (board->pos[new_x][new_y] == EMPTY || board->pos[new_x][new_y] % 2 != is_white) {
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

std::vector<Move> get_valid_moves_from(Board *board, int x, int y) {
    ChessPiece piece = board->pos[x][y];

    std::vector<Move> list;

    switch (piece) {
        case EMPTY:
            break;
        case WHITE_BISHOP:
            case BLACK_BISHOP:
                list = get_valid_bishop_moves(board, x, y);
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

std::vector<Move> get_valid_moves(Board *board) {
    std::vector<Move> move_list;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::vector<Move> tmp_moves = get_valid_moves_from(board, i, j);

            move_list.insert(move_list.end(), tmp_moves.begin(), tmp_moves.end());
        }
    }

    return move_list;
}
