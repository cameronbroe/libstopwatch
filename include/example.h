#include <string>

namespace shared_lib {

class example {
private:
    std::string m_message;

public:
    example();
    ~example();

    void setMessage(std::string message);
    std::string getMessage();
};

}
