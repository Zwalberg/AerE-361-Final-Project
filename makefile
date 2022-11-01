numgen:
	gcc numgen.c -o numgen.out

blackjack:
	gcc game.c -o blackjack.out

run_game:
	@gcc game.c -o blackjack.out
	@./blackjack.game

clean:
	rm numgen.out blackjack.game
