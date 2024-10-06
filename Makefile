# Nom de l'exécutable
NAME = morpion

# Fichiers source
SRCS = main.c \

# Règle par défaut
all: $(NAME)

# Règle pour créer l'exécutable
$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

# Règle pour nettoyer (supprimer l'exécutable)
fclean:
	rm -f $(NAME)

# Règle pour nettoyer et recompiler
re: fclean all
