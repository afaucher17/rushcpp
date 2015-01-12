CXX = /usr/local/bin/g++
RM = /bin/rm
CXXFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lncurses

NAME = ft_retro

SRC = ACharacter.cpp \
	AGameEntity.cpp \
	CollisionChecker.cpp \
	Console.cpp \
	DisplaySprite.cpp \
	Enemy.cpp \
	EnemySpawner.cpp \
	Fps.cpp \
	Game.cpp \
	Hitbox.cpp \
	InputController.cpp \
	Interval.cpp \
	Missile.cpp \
	MoveController.cpp \
	Obstacle.cpp \
	Pattern.cpp \
	Player.cpp \
	Position.cpp \
	Sprite.cpp \
	Window.cpp \
	main.cpp

OFILES = $(patsubst %.cpp,%.o, $(SRC))

all: $(NAME)

$(NAME): $(OFILES)
	@echo "Building $(NAME)"
	@$(CXX) $(LDFLAGS) $^ -o $@

ACharacter.o: ACharacter.cpp ACharacter.hpp AGameEntity.hpp \
	Console.hpp Position.hpp Hitbox.hpp Sprite.hpp DisplaySprite.hpp \
	Missile.hpp Pattern.hpp MoveController.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

AGameEntity.o: AGameEntity.cpp AGameEntity.hpp Console.hpp \
	Position.hpp Hitbox.hpp Sprite.hpp DisplaySprite.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

CollisionChecker.o: CollisionChecker.cpp CollisionChecker.hpp \
	AGameEntity.hpp Console.hpp Position.hpp Hitbox.hpp Sprite.hpp \
	DisplaySprite.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

Console.o: Console.cpp Console.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

DisplaySprite.o: DisplaySprite.cpp DisplaySprite.hpp Position.hpp \
	Sprite.hpp Console.hpp Position.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

Enemy.o: Enemy.cpp Enemy.hpp ACharacter.hpp AGameEntity.hpp \
	Console.hpp Position.hpp Hitbox.hpp Sprite.hpp DisplaySprite.hpp \
	Missile.hpp Pattern.hpp MoveController.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

EnemySpawner.o: EnemySpawner.cpp EnemySpawner.hpp Enemy.hpp \
	ACharacter.hpp AGameEntity.hpp Console.hpp Position.hpp Hitbox.hpp \
	Sprite.hpp DisplaySprite.hpp Missile.hpp  Pattern.hpp MoveController.hpp \
	 Window.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

Fps.o: Fps.cpp Fps.hpp Interval.hpp Console.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

Game.o: Game.cpp Game.hpp Player.hpp ACharacter.hpp AGameEntity.hpp \
	Console.hpp Position.hpp Hitbox.hpp Sprite.hpp DisplaySprite.hpp \
	Missile.hpp Pattern.hpp MoveController.hpp InputController.hpp \
	CollisionChecker.hpp EnemySpawner.hpp Enemy.hpp Window.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

Hitbox.o: Hitbox.cpp Hitbox.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

InputController.o: InputController.cpp InputController.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

Interval.o: Interval.cpp Interval.hpp Console.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

Missile.o: Missile.cpp Missile.hpp AGameEntity.hpp Console.hpp \
	Position.hpp Hitbox.hpp Sprite.hpp DisplaySprite.hpp Pattern.hpp \
	MoveController.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

MoveController.o: MoveController.cpp MoveController.hpp Position.hpp \
	Pattern.hpp Console.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

Obstacle.o: Obstacle.cpp Obstacle.hpp AGameEntity.hpp Console.hpp \
	Position.hpp Hitbox.hpp Sprite.hpp DisplaySprite.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

Pattern.o: Pattern.cpp Pattern.hpp Console.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

Player.o: Player.cpp ACharacter.hpp AGameEntity.hpp Console.hpp \
	Position.hpp Hitbox.hpp Sprite.hpp DisplaySprite.hpp Missile.hpp \
	Pattern.hpp MoveController.hpp Player.hpp ACharacter.hpp InputController.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

Position.o: Position.cpp Position.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

Sprite.o: Sprite.cpp Sprite.hpp Console.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

Window.o: Window.cpp Window.hpp Console.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp Window.hpp Console.hpp Interval.hpp Fps.hpp \
	Interval.hpp Position.hpp DisplaySprite.hpp Position.hpp Sprite.hpp \
	AGameEntity.hpp Hitbox.hpp DisplaySprite.hpp Game.hpp Player.hpp \
	ACharacter.hpp AGameEntity.hpp Missile.hpp Pattern.hpp MoveController.hpp \
	InputController.hpp CollisionChecker.hpp EnemySpawner.hpp Enemy.hpp \
	Window.hpp
	@echo "Creating file $@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "Deletion of building files"
	@$(RM) -rf $(OFILES)

fclean: clean
	@echo "Deletion of $(NAME)"
	@$(RM) -f $(NAME)

re: fclean all
