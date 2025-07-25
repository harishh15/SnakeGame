CFLAGS = -Wall -Iinclude `sdl2-config --cflags` -I/usr/include/SDL2
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf

OBJS = src/main.o src/game.o src/snake.o src/fruit.o src/rendering.o

snake: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o snake
