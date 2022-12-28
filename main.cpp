#include <cstdio>
#include <iostream>
#include <stdexcept>
#include "extern_example.h"

#define EXIT 0


int absolut_value(int num)
{
    if(num < 0) return - num;
    return num;
}


int sum(int number, int second_number)
{
    return number + second_number;
}

void integer_types()
{
    // they have 2bytes,4bytes or 8bytes,if long
    int one = 1;
    short int short_one = 1;
    long int long_one = 1L;
    int bits = 0b1111;
    int hexa = 0x1A2;
    unsigned int un = 1;
}


void float_types()
{
    // they have 2bytes,4bytes or 8bytes,if long
    float one = 1.22;
    float bits = 0b1111;
    float hexa = 0x1A2;
    double d = 2.3;
    long double dd = 3.1;
    float float_most_precisious = 2.3L;
}


void chr()
{
    // char = 1byte(ascii) char16_t (utf16) wchar_t (large type)
    char c = 'a';
    char16_t b = 'b';
    wchar_t sc = 'c';
    // escape char
    printf("\tb\na\vc\f");
}

void boolean()
{
    bool t = true;
    bool f = false;
}

void logical_operator()
{
    int x = 3;
    if(x == 3 && x < 10 || x > 10 and x != 3 or x == 2)
    {
        printf("always true");
    }
}


void size_types()
{
    auto variable = 3;
    size_t v = variable;
    size_t length = sizeof(int);

}


void arrays()
{
    int array[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(size_t o: array){
        printf("%zu ", o);
    }
    printf("\n");
}


// USER DEFINED TYPES
enum class Race{
    // set values with name
    DINAM,
    TEKLAN,
    MOIRAN,
};


void enumeration()
{
    Race race = Race::DINAM;
    switch (race) {
        case Race::DINAM:
            printf("race %d\n", race);
            break;
        case Race::TEKLAN:
            printf("race %d\n", race);
        default:
            break;
    }
}

// containers structs (diferent types and values)
//they are sequential in memory and they have some feature in low level
struct Book{
    char name[30];
    int year;
    void method()
    {

    }

    private:
        int x;
};

typedef struct Book2{
    char* name = "name";
    int year;
};


void structs()
{
    struct Book b;
    b.name;
    Book2 b2;
    b2.name;
}

// union (exist at the moment)
union U{
    int num;
    char x;
};


void union_use()
{
    union U iz;
    iz.num = 2;
    printf("\n%d", iz.num);
    // override
    iz.x = 'a';
    printf("\n%c %d ",iz.x,iz.num);
}


// class
// there is no one diference between class and struct, but, structs, by default have public methods

class Lion{
public:
    int get_age()
    {
        return age;
    }

    void set_age(int new_age){
        age = new_age;
    }

    void show_age(int a)
    {
        printf("%d", a);
    }

private:
    int age;
};


class New2{


    void show()
    {
        printf("\nshow %d\n", this->value);
    }

public:
    ~New2(){
        // this is a destructor
    }
    New2(){

    }
    New2(int value){
        this->value = value;
    }

    int get_value()
    {
        return this->value;
    }

private:
    int value;
};

void class_use()
{
    Lion lion = Lion();
    lion.set_age(23);
    lion.show_age(lion.get_age());

}

// Exercises
enum class Operation{
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
};

class Calculator{
public:
    Calculator(Operation op, int num1, int num2){
        this->op = op;
        this->num = num1;
        this->num2 = num2;
    }
    void result()
    {
        printf("\nR: %d", operator1());
    }

private:
    Operation op;
    int num;
    int num2;

    int operator1(){
        switch (this->op) {
            case Operation::ADD:
                return num + num2;
            case Operation::SUBTRACT:
                return num - num2;
            case Operation::MULTIPLY:
                return num * num2;
            case Operation::DIVIDE:
                return num / num2;
            default:
                return 0;
        }
    }

};

void other()
{
    New2 new2 {2222};
    printf("\n%d", new2.get_value());
    New2{};
    printf("\n%d", new2.get_value());
}

struct UseWithPtr{
    int num {24};
};

struct UseWithPtr v;
UseWithPtr* vv = &v;


//pointers
void use_ptr()
{
    printf("\n%d", vv->num );
    int an_object {0};
    int* ptr {&an_object};
    std::cout << "\nThe address to an_object: " <<  ptr << '\n';
    std::cout << "The value of an_object: " << *ptr << '\n'; //dereference
    int ba[] {1, 2, 3};
    int* xz2{ba};
    std::cout << ++(*xz2);
}


// references are the most safe and convenient version of pointers
void reference_function(int& vector)
{
    printf("\n");
    for(size_t i = 0 ; i < 4; i++)
    {
        std::cout << (vector)++<< ' ';
    }
}


// pointer based data structure (linked list)

class LinkedList{

public:
    LinkedList* next{};


    void insert_data(LinkedList* next_value)
    {
        next_value->next = next;
        next = next_value;
    }

    short int number;

};


void use_basic_linked_list()
{
    LinkedList v1, v2, v3;
    v1.number = 1;
    v2.number = 2;
    v3.number = 3;
    v1.insert_data(&v2);
    v2.insert_data(&v3);


    for(LinkedList* value = &v1; value; value = value->next){
        std::cout << value->number << ' ';
    }
}


// const methods read-only

class ConstClass{
public:
    [[nodiscard]] int get_value() const
    {
        return this->value;
    }
private:
    int value {333};
};


// auto is recomended type in loops
struct LinkedList2{
    LinkedList2* next{};
    LinkedList2* before{};

    void insert_before(LinkedList2* after, LinkedList2* before)
    {
        //this->next = value;
        this->next = after;
        after = this->next;
        this->before = before;
        before = this->before;
    }

    [[nodiscard]] int get_num() const{
        return this->num;
    }

    void set_num(int va)
    {
        this->num = va;
    }

private:
    int num;
};


[[noreturn]] void test_linkedl2()
{
    struct LinkedList2 l2, l3, l4;
    l4.set_num(14);
    l3.set_num(26);
    l2.set_num(35);

    l4.insert_before(&l3, nullptr);
    l3.insert_before(&l2, &l4);
    l2.insert_before(nullptr, &l3);

    std::cout << '\n';
    LinkedList2* v11 = &l4;
    bool validation = false;
    for(;;)
    {
        std::cout <<  v11->get_num() << ' ' ;
        if(v11->next == nullptr) {
            std::cout <<  v11->get_num() << ' ' ;
            validation = true;
        }
        if(validation)  v11 = v11->before;
        else v11 = v11->next;
        if(v11->before == nullptr) {
             validation = false;
        }
    }
}


// static objects and members


static int val = 0;

int vvvv()
{
    static int val1 = 2;  // until program finish

    return val1;
}


class Static{
public:

    static std::string fn()
    {
        return "DO NOTHING";
    }
};


void TestStatic()
{
    std::cout << '\n' << val << ' ' << vvvv() << ' ' << Static::fn() << '\n';
}

extern const float PI1; //says to compiler that there is a another variable already declared.


void dynamic_array()
{
    // arrays with dynamic storage duration
    int* da {new int[100]};
    for(size_t i = 0; i < 100; i++){
        std::cout << (*da)++ << ' ';
    }
    delete[] da; // ever

}


void except(int x)
{
    // exceptios are types that communicate an error condition

    try{
        if(x == 0xFACE){
            throw std::runtime_error{"ERROR: RUNTIME"};
        }
    }catch (const std::runtime_error &e){
        printf("ERROR:: %s", e.what());
    }

}

int main()
{
    std::cout << '\n' << val << ' ' << vvvv() << ' ' << Static::fn() << '\n';
    printf("Value %d\n", absolut_value(-3));
    printf("The sum is %d\n", sum(10023, 3212));
    chr();
    arrays();
    enumeration();
    union_use();
    class_use();
    other();
    Operation p {Operation::ADD};
    Calculator c{p, 1, 2};
    c.result();
    use_ptr();
    int array1[] {13, 21, 39, 41};
    reference_function(array1[0]);
    printf("\n");
    use_basic_linked_list();
    ConstClass cc;
    std::cout << '\n' << cc.get_value();
    //test_linkedl2();
    TestStatic();

    std::cout << PI1;
    dynamic_array();
    except(0xFACE);
    return EXIT;
}
