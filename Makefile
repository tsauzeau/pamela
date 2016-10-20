NAME		= pamela

LIBNAME		= pam_$(NAME).so

CC		= g++ -g

CP		= cp

SRCDIR		= src

OBJDIR		= obj

SRC		= pam.c

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
	$(CC) -shared -o $(LIBNAME) $(OBJ) $(LIDFLAGS)

all: $(LIBNAME)

install: all
	$(CP) $(LIBNAME) /lib/x86_64-linux-gnu/security/$(LIBNAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(LIBNAME)

re: fclean all

.PHONY: all clean fclean re ui doc
