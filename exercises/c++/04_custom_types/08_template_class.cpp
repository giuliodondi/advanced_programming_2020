#include <iostream>
#include <string>

template <typename T>
class Vector {
  std::size_t _size;
  T* elem;

 public:
  Vector(const std::size_t size) : elem{new T[size]}, _size{size} {}

  // automatically release the acquired memory
  ~Vector() { delete[] elem; }

  // try to remove the const and recompile
  std::size_t size() const { return _size; }

  T& operator[](const std::size_t i) { return elem[i]; }

  // try to comment this line and recompile
  const T& operator[](const std::size_t i) const { return elem[i]; }
  
  //my new functions
  
  //access the last element
   T& end() {
    return elem[_size-1]; 
  }

  //resize the vector
  void resize( const std::size_t _new_size);
  
  //add a new element at the end of the vector
  void push_back( const T& new_elem ) {
    resize( _size + 1);
    end() = new_elem;
  }
  
};

template <typename T >
void Vector<T>::resize( const std::size_t _new_size) {
    T* tmp{new T[_new_size]};
    const auto l = std::min( _size, _new_size);
    for (auto i=0u; i<l; ++i) {
      tmp[i] = elem[i]; 
    }
    _size = _new_size;
    delete[] elem;
    elem = tmp;
    
  }

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
  for (auto i = 0u; i < v.size(); ++i)
    os << "v[" << i << "] = " << v[i] << std::endl;
  //const T* const end{ v + v.size() };
  //auto i{0u};
  //for (; v!=end; ++v ) {
  //  os << "v[" << i++ << "] = " << v << std::endl;
  //}
  return os;
}

int main() {
  Vector<double> v{10};

  for (auto i = 0u; i < v.size(); ++i)
    v[i] = i;

  //test of my new functions
  v.resize( 11 );
  v.end() = 111;
  v.push_back(222);
  
  std::cout << v << std::endl;

  Vector<double>* pv{&v};

  // first dereference the pointer, then I can use the defined operators
  (*pv)[0] = -99.999;

  pv->operator[](1) = 77777.3333;  // or I call the function by name

  std::cout << *pv << std::endl;

  Vector<double>& rv{v};

  rv[5] = 555;

  std::cout << v << std::endl;

  return 0;
}
