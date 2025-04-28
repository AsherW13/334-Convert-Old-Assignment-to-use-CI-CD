FROM ubuntu:latest

RUN apt-get update && \
    apt-get install -y g++ make

WORKDIR /app

COPY . .
COPY Makefile ./

RUN make

CMD ["./treeTester.out"]
