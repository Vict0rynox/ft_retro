NAME = ft_retro

CC = clang++

CFLAGS = -Wall -Werror -Wextra

SOURCE_FILES = src/main.cpp
    src/control/IController.hpp
    src/control/BaseController.cpp
    src/control/BaseController.hpp
    src/control/ExitController.cpp
    src/control/ExitController.hpp
    src/utils/IIterrator.hpp
    src/view/ObjectViewer.hpp
    src/view/ObjectViewer.cpp
    src/view/ObjectViewer.hpp
    src/view/IViewer.hpp
    src/view/ButtonKeyViewer.cpp
    src/view/ButtonKeyViewer.hpp
    src/control/PlayerController.cpp
    src/control/PlayerController.hpp
    src/view/FPSViewer.cpp
    src/view/FPSViewer.hpp
    src/event/IEvent.hpp
    src/event/MoveEvent.cpp
    src/event/MoveEvent.hpp
    src/model/Bullet.cpp
    src/model/Bullet.hpp
    src/event/IEvent.cpp
    src/event/ObjectCreatorEvent.cpp
    src/event/ObjectCreatorEvent.hpp
    src/model/factory/IObjectFactory.cpp
    src/model/factory/IObjectFactory.hpp
    src/model/Stars.cpp
    src/model/Stars.hpp
    src/model/Enemies.cpp
    src/model/Enemies.hpp
    src/model/factory/UnitFactory.cpp
    src/model/factory/UnitFactory.hpp
    src/utils/isSame.hpp
    src/event/GameOverEvent.cpp
    src/event/GameOverEvent.hpp
    src/core/Application.cpp
    src/core/Application.hpp
    src/core/TickRate.cpp
    src/core/TickRate.hpp
    src/utils/List.hpp
    src/utils/ListNode.hpp
    src/model/Unit.cpp
    src/model/Unit.hpp
    src/model/Object.hpp
    src/model/Object.cpp
    src/model/INcursesView.hpp
    src/model/Player.cpp
    src/model/Player.hpp
    src/model/Position.cpp
    src/model/Position.hpp
    src/model/Simbol.cpp
    src/model/Simbol.hpp
    src/model/Size.cpp
    src/model/Size.hpp

HEADER_FILES = $(SOURCE_FILES:.hpp=.hpp)

OBJ_FILES = $(SOURCE_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(OBJ_FILES) $(CFLAGS) -o $(NAME)

%.o: %.cpp .h .hpp
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
