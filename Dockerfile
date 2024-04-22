FROM alpine:3.19

RUN apk add --no-cache make lua5.4 fennel5.4
RUN ln -s /usr/bin/fennel5.4 /usr/bin/fennel

WORKDIR /zmk
COPY Makefile chords.txt ./
COPY src src/

CMD ["make", "all"]
