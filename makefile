ODIR = bin
SRC = src
CC = gcc
GAMEEXE = blackjack.out


numgen:
	$(CC) $(SRC)/numgen.c -o $(ODIR)/numgen.out

game:
	$(CC) $(SRC)/game.c -o $(ODIR)/$(GAMEEXE)

run_game: game
	@echo "Running game\n"
	@./$(ODIR)/$(GAMEEXE)

clean:
	@find . -type f -name '*.out' -delete