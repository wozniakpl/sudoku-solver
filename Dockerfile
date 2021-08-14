FROM ubuntu:bionic

WORKDIR /susolver

RUN apt update 
RUN apt install -y python3 python3-pip

ADD dependencies_pip.txt .
RUN pip3 install -r dependencies_pip.txt

ADD dependencies.txt .
RUN xargs -a dependencies.txt apt install -y 

ADD dependencies_dev.txt .
RUN xargs -a dependencies_dev.txt apt install -y 
RUN cd /usr/src/googletest ; cmake . ; cmake --build . --target install
RUN mkdir -m 777 /.cache ; mkdir -m 777 /.ccache

ADD dependencies_dev_pip.txt .
RUN pip3 install -r dependencies_dev_pip.txt

