numgen:
	gcc numgen.c -o numgen.out

blackjack:
	gcc game.c -o blackjack.game

run_game:
	@gcc game.c -o blackjack.game
	@./blackjack.game

clean:
	rm numgen.out blackjack.game