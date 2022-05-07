MAKEFLAGS += --no-print-directory

CC := gcc
CFLAGS := -Wall

target := Galo

tocompile := $(shell find . -name "*.c")
objs := $(patsubst %.c,%.o,$(tocompile))
deps := $(patsubst %.c,%.d,$(tocompile))

DEPFLAGS = -MMD -MF $(@:.o=.d)

END ="\e[1;36mFinished compiling \e[0m"

all: $(target) clean
	@echo $(END)

$(target): $(objs)
	@$(CC) $(CFLAGS) -o $(target) $^
%.o: %.c
	@$(CC) $(CFLAGS) -c $< $(DEPFLAGS) -o  $@

clean:
	@rm  -f $(shell find . -name "*.d")

superclean:
	@rm  -f $(shell find . -name "*.d" -or -name "*.o") $(target)