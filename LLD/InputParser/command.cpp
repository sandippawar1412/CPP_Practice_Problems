#include <bits/stdc++.h>
using namespace std;

class ICommand
{
public:
    virtual bool matches(string) = 0;
    virtual void execute(string) = 0;
};

class StartGame : public ICommand
{
public:
    bool matches(string str)
    {
        return true;
    }

    void execute(string command)
    {
    }
};

class CreateUser : public ICommand
{
public:
    bool matches(string str)
    {
        auto pos = str.find(' ');
        if (pos != string::npos)
        {
            auto command = str.substr(0, pos);
            // cout << command << endl;
            transform(command.begin(), command.end(), command.begin(), ::toupper);
            if (command == "CREATEUSER")
            {
                return true;
            }
        }
        return false;
    }

    void execute(string command)
    {
        cout << "user created -> " << command << endl;
    }
};

class CommandReistry
{
    vector<ICommand *> commands;

public:
    void registerCommand(ICommand *command)
    {
        commands.emplace_back(command);
    }

    void executeCommand(string str)
    {
        for (auto &command : commands)
        {
            if (command->matches(str))
                command->execute(str);
        }
    }
};

int main()
{
    CommandReistry *commandRegistery = new CommandReistry();
    commandRegistery->registerCommand(new CreateUser());
    int no = 2;
    while (no--)
    {
        string inp;
        cout << "Enter command: ";
        getline(cin, inp);
        commandRegistery->executeCommand(inp);
    }
}