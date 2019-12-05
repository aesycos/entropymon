CC		:= clang 
CFLAGS	:= -Wall -Os -lncurses -ltinfo
INC		:= inc 


BINDIR 	:= bin
SRCDIR 	:= src
OBJDIR	:= obj

SRC		:= $(wildcard $(SRCDIR)/*.c)
OBJ  	:= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))
TARGET	:= entropymon

INPATH 	:= /usr/local/bin/

all: $(TARGET)
	strip -s $(BINDIR)/$(TARGET)
	@echo "Build completed successfully"

$(TARGET): $(OBJ)
	@$(CC) $(CFLAGS) -I$(INC) -o $(BINDIR)/$(TARGET) $^
	@echo "LD $^"

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) -I$(INC) -c -o $@ $<
	@echo "CC $^"

clean: 
	rm -rf $(OBJDIR)/*.o

cleanall: clean
	rm -rf bin/$(TARGET)
	@echo "Now we are squeaky :3"

install: $(BINDIR)/$(TARGET)
	cp $< $(INPATH)

