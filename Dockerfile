FROM ubuntu:latest

RUN apt-get update && apt-get install -y build-essential

WORKDIR /sttcse_24110131_24110318

COPY . .

RUN make clean && make

ENTRYPOINT ["./randfuncs"]