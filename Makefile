##
## Makefile for my_ftp in /home/thomas/Projects/Epitech/Tek2/my_ftp
## 
## Made by Thomas Sauzeau
## Login   <thomas@epitech.net>
## 
## Started on  Sun May 15 21:34:56 2016 Thomas Sauzeau
## Last update Sun May 15 21:35:05 2016 Thomas Sauzeau
##

NAME		= pam

CC		= gcc -g

SRCDIR		= src

OBJDIR		= obj

SRC		= main.c

OBJ		= $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

CXXFLAGS	+= -W -Wall -Wextra
CXXFLAGS	+= -Iinclude

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@if [ ! -d $(OBJDIR) ] ; then mkdir $(OBJDIR) ; fi
	@if [ ! -d $(OBJDIR)/exec ] ; then mkdir $(OBJDIR)/exec ; fi
	$(CC) $(CXXFLAGS) $(FPIC) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(CXXFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

all: $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re ui doc
