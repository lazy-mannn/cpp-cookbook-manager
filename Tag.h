#ifndef TAG_H
#define TAG_H

#include <string>
#include <ostream>

class Tag {
private:
    int id;
    std::string name;

public:
    Tag(int id, std::string name);

    int getId() const;
    std::string getName() const;

    friend std::ostream& operator<<(std::ostream& out, const Tag& t);
};

#endif
