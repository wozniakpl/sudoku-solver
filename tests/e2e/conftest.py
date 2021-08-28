import os
import pytest
import subprocess
from pytest import fixture


def pytest_addoption(parser):
    parser.addoption("--build-dir", action="store")


def run_subprocess(args):
    return subprocess.run(
        args,
        check=False,
        encoding="utf8",
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )


class App:
    def __init__(self, build_dir):
        self.arguments = []
        self.build_dir = build_dir

    def invoke(self):
        here = os.path.dirname(os.path.realpath(__file__))
        binary_dir = os.path.abspath(os.path.join(self.build_dir, "bin", "susolver"))
        invocation = [binary_dir, *self.arguments]
        self.arguments = []
        result = run_subprocess(invocation)
        return result

    def help(self):
        self.arguments.append("--help")
        return self

    def inline(self, text):
        self.arguments.extend(["--inline", str(text)])
        return self

    def generate(self, size):
        self.arguments.extend(["--generate", str(size)])
        return self

    def with_solution(self):
        self.arguments.append("--with-solution")
        return self


@pytest.fixture
def app(request):
    build_dir = request.config.getoption("--build-dir")
    if build_dir == None:
        raise ValueError("--build-dir must be set")
    return App(build_dir)
