import copy
import pytest


def run_successfully(application):
    result = application.invoke()
    assert result.returncode == 0
    assert len(result.stdout) > 0
    assert len(result.stderr) == 0
    return result


def test_running_without_args(app):
    _ = run_successfully(app)


def test_running_help(app):
    _ = run_successfully(app)


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


def create_medium_problem():
    problem = copy.deepcopy(testing_board)
    for i in range(0, 5):
        problem[7][i] = 0
    problem[8] = zeros

    return case(problem, testing_board)


def test_solving_simple_sudoku(app):
    sudoku, solution = create_simple_problem()
    result = run_successfully(app.inline(sudoku))
    assert result.stdout.rstrip() == solution


@pytest.mark.skip(reason="not fast yet")
def test_solving_medium_sudoku(app):
    sudoku, solution = create_medium_problem()
    result = run_successfully(app.inline(sudoku))
    assert result.stdout.rstrip() == solution


@pytest.mark.parametrize("size", [1, 5, 10])
def test_generating_random_board(app, size):
    result = run_successfully(app.generate(size))
    board = result.stdout.rstrip()
    assert len(board) == 81
    assert list(board).count("0") == size
