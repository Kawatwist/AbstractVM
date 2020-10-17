
enum eBase {Int8 = 0, Other = 1};

class Ibase // Ioperator
{
    public :
        virtual eBase    getType(void) const= 0;
};

template<typename T>
class Type1 : public Ibase
{
    public :
        Type1() {this->type = Int8;};
        ~Type1() {};
        eBase getType() const {return this->type;};
    protected :
        T var;
        eBase type;
};

template<typename T>
class Type2 : public Ibase
{
    public :
        Type2() {this->type = Other;};
        ~Type2() {};
        eBase getType() const {return this->type;};
    protected :
        T var;
        eBase type;
};

/* Factory */

template<typename T>
class Top : public Ibase
{
    public :
        Top() {};
        ~Top() {};
        eBase getType() const {return (Int8);};
        Ibase * CreateType(int val) {if (val == 0) return (new Type1<int>()); return (new Type2<float>());};
};