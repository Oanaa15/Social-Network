cmake_minimum_required(VERSION 3.21)
project(proiectSDA)

set(CMAKE_CXX_STANDARD 14)

add_executable(proiectSDA main.cpp Domain/User.cpp Domain/User.h Tests/Tests.cpp Tests/Tests.h Domain/LSI.h Domain/Node.h Domain/Multimap.h Repository/RepositoryUser/RepositoryUser.cpp Repository/RepositoryUser/RepositoryUser.h Domain/Friendship.cpp Domain/Friendship.h Repository/RepositoryFriendship/RepositoryFriendship.cpp Repository/RepositoryFriendship/RepositoryFriendship.h Domain/Message.cpp Domain/Message.h Repository/RepositoryMessage/RepositoryMessage.cpp Repository/RepositoryMessage/RepositoryMessage.h Service/ServiceUser/ServiceUser.cpp Service/ServiceUser/ServiceUser.h Service/ServiceFriendship/ServiceFriendship.cpp Service/ServiceFriendship/ServiceFriendship.h Service/ServiceMessage/ServiceMessage.cpp Service/ServiceMessage/ServiceMessage.h Domain/Event.cpp Domain/Event.h Repository/RepositoryEvent/RepositoryEvent.cpp Repository/RepositoryEvent/RepositoryEvent.h Service/ServiceEvent/ServiceEvent.cpp Service/ServiceEvent/ServiceEvent.h Network/Network.cpp Network/Network.h "User Interface/Console.cpp" "User Interface/Console.h")
