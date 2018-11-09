#include <eosiolib/eosio.hpp>

using namespace eosio;
using eosio::print;

#define EVENTKV(key, value) \
{ \
  print('"'); \
  print(key); \
  print('"'); \
  print(':'); \
  print('"'); \
  print(value); \
  print('"'); \
  print(",");\
} while(0);

#define EVENTKVL(key, value) \
{ \
  print('"'); \
  print(key); \
  print('"'); \
  print(':'); \
  print('"'); \
  print(value); \
  print('"'); \
} while(0);

#define START_EVENT(etype, version) \
  print("{"); \
  EVENTKV("version",version) \
  EVENTKV("etype",etype) 

#define END_EVENT() \
  print("}\n");
  
#define EMIT_SOMETEST_EVENT(number, field1) \
    START_EVENT("someevent", "1.3") \
    EVENTKV("number", std::to_string(number).c_str()) \
    EVENTKVL("field1", field1) \
    END_EVENT()
    

CONTRACT helloworld : public eosio::contract {
  public:
      using contract::contract;

      ACTION hi( uint64_t number ) {
         EMIT_SOMETEST_EVENT(number, "321")
         
      }
};

EOSIO_DISPATCH( helloworld, (hi) )