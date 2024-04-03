CC = gcc

SRCDIR=src
OUTDIR=out
LDDIR=$(SRCDIR)/lib

SRCS=$(wildcard $(SRCDIR)/*.c)
OBJS=$(patsubst $(SRCDIR)/%.c, $(OUTDIR)/%.o, $(SRCS))
LDLIBS=$(patsubst $(LDDIR)%.c, $(OUTDIR)/%.so, $(SRCS))

INCLUDE=-Iinclude

$(OUTDIR)/%.o : $(SRCDIR)/%.c Makefile
	$(CC) -c $< $(INCLUDE) -o $@

PROJ_NAME=trie

all: $(OBJS)
	$(CC) $^ -o $(PROJ_NAME)

configure:
	mkdir out
	mkdir shared

clean:
	rm -rf out/* && rm -f $(PROJ_NAME)
	rmdir out shared
