#include "passserver.h"

// Xian: in a shell, type "man crypt", and the MD5 can be found (which uses 22 characters of the password), and the usage will be shown as well.
// Note that it takes c_str, char [], not string directly as the input arguments.
string PassServer::encrypt(const string &str)
{
    char salt[] = "$1$########";
    char *password = new char[35];
    strcpy(password, crypt(str.c_str(), salt));

    string pword(password);
    string delim = "$";
    int pos = pword.find(delim, 0);
    pos = pword.find(delim, pos + 1);
    pos = pword.find(delim, pos + 1);
    pword.erase(0, pos + 1);
    return pword;
    /*char salt[] = "$1$########";
    string ret = crypt(str.c_str(), salt);
    return ret.substr(1, 22);*/
}

// Constructor
PassServer::PassServer(size_t size) : h(size) {}

// Destructor
PassServer::~PassServer()
{
    h.clear(); // Clears the hash table
}

// Load user data from a file
bool PassServer::load(const char *filename)
{
    return h.load(filename);
}

// Add a user with username and password
bool PassServer::addUser(std::pair<string, string> &kv)
{
    if (h.contains(kv.first))
    {
        std::cout << "Error: User already exists.\n";
        return false;
    }

    kv.second = encrypt(kv.second);
    return h.insert(kv);
}

// Move version of addUser
bool PassServer::addUser(std::pair<string, string> &&kv)
{
    if (h.contains(kv.first))
    {
        std::cout << "Error: User already exists.\n";
        return false;
    }

    kv.second = encrypt(kv.second);
    return h.insert(std::move(kv));
}

// Remove a user with a given username
bool PassServer::removeUser(const string &k)
{
    return h.remove(k);
}

// Change a user's password
bool PassServer::changePassword(const std::pair<string, string> &p, const string &newpassword)
{
    if (!h.contains(p.first))
    {
        std::cout << "Error: User not found.\n";
        return false;
    }

    auto encrypted_current = encrypt(p.second);
    if (!h.match({p.first, encrypted_current}))
    {
        std::cout << "Error: Current password is incorrect.\n";
        return false;
    }

    auto encrypted_new = encrypt(newpassword);
    if (encrypted_current == encrypted_new)
    {
        std::cout << "Error: New password must be different from the current password.\n";
        return false;
    }

    return h.insert({p.first, encrypted_new});
}

// Check if a user exists
bool PassServer::find(const string &user) const
{
    return h.contains(user);
}

// Show structure and contents of the hash table
void PassServer::dump() const
{
    h.dump();
}

// Return the size of the PassServer
size_t PassServer::size() const
{
    return h.size();
}

// Save the username and password combinations into a file
bool PassServer::write_to_file(const char *filename) const
{
    return h.write_to_file(filename);
}
