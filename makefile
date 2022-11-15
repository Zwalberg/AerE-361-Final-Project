numgen:
	gcc numgen.c -o numgen.out

blackjack:
	gcc game.c -o blackjack.out

run_game:
	@gcc game.c -o blackjack.out
	@echo "Running game\n"
	@./blackjack.out

clean:
	rm numgen.out blackjack.out
