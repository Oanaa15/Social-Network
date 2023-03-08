#include <iostream>
#include "Tests/Tests.h"
#include "Domain/User.h"
#include "Domain/LSI.h"
#include "Domain/Friendship.h"
#include "Domain/Multimap.h"
#include "Repository/RepositoryUser/RepositoryUser.h"
#include "Repository/RepositoryMessage/RepositoryMessage.h"
#include "Repository/RepositoryFriendship/RepositoryFriendship.h"
#include "Repository/RepositoryEvent/RepositoryEvent.h"
#include "Service/ServiceUser/ServiceUser.h"
#include "Service/ServiceFriendship/ServiceFriendship.h"
#include "Service/ServiceMessage/ServiceMessage.h"
#include "Service/ServiceEvent/ServiceEvent.h"
#include "Network/Network.h"
#include "User Interface/Console.h"

int main() {
    run_tests();
    RepositoryUser repositoryUser("users.txt");
    RepositoryFriendship repositoryFriendship("friendships.txt");
    RepositoryMessage repositoryMessage("messages.txt");
    RepositoryEvent repositoryEvent("events.txt");

    ServiceUser serviceUser(repositoryUser);
    ServiceFriendship serviceFriendship(repositoryFriendship);
    ServiceMessage serviceMessage(repositoryMessage);
    ServiceEvent serviceEvent(repositoryEvent);

    Network network(serviceUser, serviceFriendship, serviceMessage, serviceEvent);

    Console console(network);
    console.run_menu();

    return 0;
}
