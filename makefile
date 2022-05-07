MAKEFLAGS += --no-print-directory

CC := gcc
CFLAGS := -Wall

target := Galo

tocompile := $(shell find . -name "*.c")
objs := $(patsubst %.c,%.o,$(tocompile))
deps := $(patsubst %.c,%.d,$(tocompile))


DEPFLAGS = -MMD -MF $(@:.o=.d)


all: $(target) clean

Galo: $(objs)
	$(CC) $(CFLAGS) -o $(target) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< $(DEPFLAGS) -o  $@


clean:
	@rm  -f $(shell find . -name "*.d")

list:
	$(info ${objs})

	