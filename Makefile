NAME		= pamela

LIBNAME		= pam_$(NAME).so

CC		= gcc -g

CP		= cp

SRCDIR		= src

OBJDIR		= obj

SRC		= main.c

OBJ		= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

LDFLAGS		= -lpam -lpam_misc

CFLAGS		+= -W -Wall -Wextra
CFLAGS		+= -Iinclude
CFLAGS		+= -fPIC -fno-stack-protector

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@if [ ! -d $(OBJDIR) ] ; then mkdir $(OBJDIR) ; fi
	@if [ ! -d $(OBJDIR)/exec ] ; then mkdir $(OBJDIR)/exec ; fi
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBNAME): $(OBJ)
	ld -x --shared -o $(LIBNAME) $(OBJ)

all: $(LIBNAME)

install: all
	$(CP) $(LIBNAME) /lib/security/$(LIBNAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(LIBNAME)

re: fclean all

.PHONY: all clean fclean re ui doc
