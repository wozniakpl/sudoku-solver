import copy
import pytest


def run_successfully(application):
    result = application.invoke()
    assert result.returncode == 0
    assert len(result.stdout) > 0
    assert len(result.stderr) == 0
    return result


def to_string(board):
    return "".join(["".join([str(item) for item in arr]) for arr in board])


testing_board = [
    [1, 2, 3, 4, 5, 6, 7, 8, 9],
    [4, 5, 6, 7, 8, 9, 1, 2, 3],
    [7, 8, 9, 1, 2, 3, 4, 5, 6],
    [2, 3, 4, 5, 6, 7, 8, 9, 1],
    [5, 6, 7, 8, 9, 1, 2, 3, 4],
    [8, 9, 1, 2, 3, 4, 5, 6, 7],
    [3, 4, 5, 6, 7, 8, 9, 1, 2],
    [6, 7, 8, 9, 1, 2, 3, 4, 5],
    [9, 1, 2, 3, 4, 5, 6, 7, 8],
]

zeros = [0, 0, 0, 0, 0, 0, 0, 0, 0]


def case(candidate, solved):
    good = to_string(solved)
    assert "0" not in good
    return to_string(candidate), good


def create_simple_problem():
    problem = copy.deepcopy(testing_board)
    problem[8] = zeros

    return case(problem, testing_board)


def test_running_without_args(app):
    _ = run_successfully(app)


def test_running_help(app):
    _ = run_successfully(app.help())


def get_solution(result):
    return result.stdout.rstrip()


def test_solving_simple_sudoku(app):
    sudoku, solution = create_simple_problem()
    result = run_successfully(app.inline(sudoku))
    assert get_solution(result) == solution


def generate_board_without_solution(app, size):
    result = run_successfully(app.generate(size))
    board = result.stdout.rstrip()
    assert len(board) == 81
    assert list(board).count("0") == size
    return board


def generate_board_with_solution(app, size):
    result = run_successfully(app.generate(size).with_solution())
    lines = result.stdout.rstrip().split("\n")
    assert len(lines) == 2
    board = lines[0]
    solution = lines[1]
    assert len(board) == 81
    assert len(solution) == 81
    assert list(board).count("0") == size
    assert list(solution).count("0") == 0
    return board, solution


@pytest.mark.parametrize("size", [1, 5, 10])
def test_generating_random_board(app, size):
    _ = generate_board_without_solution(app, size)


@pytest.mark.parametrize("size", [1, 5, 10])
def test_solving_random_board(app, size):
    board, solution = generate_board_with_solution(app, size)
    result = run_successfully(app.inline(board))
    assert get_solution(result) == solution
