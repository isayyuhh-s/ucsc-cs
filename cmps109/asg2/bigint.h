// $Id: bigint.h,v 1.16 2014-07-02 20:01:17-07 - - $
// Isaiah Solomon
// icsolomo
// 1344680
// Wesley Mackey
// CMPS 109
// 2/2/2015

#ifndef __BIGINT_H__
#define __BIGINT_H__

#include <exception>
#include <iostream>
#include <utility>
using namespace std;

#include "debug.h"

//
// Define class bigint
//
class bigint
{
      friend ostream& operator<< (ostream&, const bigint&);
   private:
      using digit_t = unsigned char;
      using bigvalue_t = vector<digit_t>;
      bool negative = false;
      bigvalue_t big_value; 
      using quot_rem = pair<bigvalue_t,bigvalue_t>;
      friend quot_rem divide (const bigvalue_t&, const bigvalue_t&);
      friend void multiply_by_2 (bigvalue_t& value);
      friend void divide_by_2 (bigvalue_t& value);
      bigvalue_t do_bigadd (const bigvalue_t& left, const bigvalue_t& right);
      bigvalue_t do_bigsub (const bigvalue_t& left, const bigvalue_t& right);
      bigvalue_t do_bigmul (const bigvalue_t& left, const bigvalue_t& right);
      bool do_bigless (const bigvalue_t& left, const bigvalue_t& right);
   public:

      //
      // Ensure synthesized members are genrated.
      //
      bigint() = default;
      bigint (const bigint&) = default;
      bigint (bigint&&) = default;
      bigint& operator= (const bigint&) = default;
      bigint& operator= (bigint&&) = default;
      ~bigint() = default;

      //
      // Extra ctors to make bigints.
      //
      bigint (const long);
      bigint (const string&);

      //
      // Basic add/sub operators.
      //
      friend bigint operator+ (const bigint&, const bigint&);
      friend bigint operator- (const bigint&, const bigint&);
      friend bigint operator+ (const bigint&);
      friend bigint operator- (const bigint&);
      long to_long() const;

      //
      // Extended operators implemented with add/sub.
      //
      friend bigint operator* (const bigint&, const bigint&);
      friend bigint operator/ (const bigint&, const bigint&);
      friend bigint operator% (const bigint&, const bigint&);

      //
      // Comparison operators.
      //
      friend bool operator== (const bigint&, const bigint&);
      friend bool operator<  (const bigint&, const bigint&);
};

//
// The rest of the operators do not need to be friends.
// Make the comparisons inline for efficiency.
//

bigint pow (const bigint& base, const bigint& exponent);

inline bool operator!= (const bigint &left, const bigint &right)
{
   return not (left == right);
}
inline bool operator>  (const bigint &left, const bigint &right)
{
   return right < left;
}
inline bool operator<= (const bigint &left, const bigint &right)
{
   return not (right < left);
}
inline bool operator>= (const bigint &left, const bigint &right)
{
   return not (left < right);
}

#endif

