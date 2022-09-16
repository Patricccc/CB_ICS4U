#include <bits/stdc++.h>
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
using namespace std;
#define mp make_pair
#define pb push_back
#define pf push_front
#define PF pop_front
#define PB pop_back
#define P push
#define F first
#define S second
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define PI 3.14159265
#define len(s) (int)s.length()
#define sz(s) (int)s.size()
#define sp(x) fixed << setprecision(x)
#define all(a) a.begin(),a.end()
typedef long long ll;
typedef string str;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll>pll;
typedef pair<double,double>pdd;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ld,ld>pld;
typedef pair<str,str>pss;
typedef pair<char,char>pcc;
typedef pair<long,long>pl;
typedef pair<bool,bool>pbb;
const ll MOD = 1000000007;
const ll MOD2 = 1000000009;
const ll high= (ll)(1e15);
const ll MOD3=998244353;
namespace IO {
#define INTERACTIVE_INPUT 0
  template <class T> struct is_iterator {
    template <class U, typename enable_if<
        !is_convertible<U, const char *>::value, int>::type = 0>
    static constexpr auto has_indirection(int)
        ->decltype(*declval<U>(), bool()) {
      return true;
    }
    template <class>
    static constexpr bool has_indirection(long) { return false; }
    static constexpr bool value = has_indirection<T>(0);
  };
  constexpr const int _bufSize = 1 << 16, _maxNumLength = 128;
  char _inputBuf[_bufSize + 1], *_inputPtr = _inputBuf, _sign, _c, _last = -1;
  char *_tempInputBuf = nullptr, _tempOutputBuf[_maxNumLength];
  char _outputBuf[_bufSize], _numBuf[_maxNumLength], _fill = ' ';
  int _cur, _tempOutputPtr = 0, _outputPtr = 0, _cnt, _numPtr = 0;
  int _width = 0, _precision = 9;
  const char *_delimiter = " "; unsigned long long _precisionBase = 1000000000;
  FILE *_input = stdin, *_output = stdout, *_error = stderr;
#if INTERACTIVE_INPUT
  char _getchar() { return _last = getchar(); }
#else
  char _getchar() {
    if (!*_inputPtr)
      _inputBuf[fread(_inputPtr = _inputBuf, 1, _bufSize, _input)] = '\0';
    return _last = *_inputPtr++;
  }
#endif
  char _getcharskipr() {
    while (_getchar() == '\r');
    return _last;
  }
  template <class I> void _readSigned(I &x) {
    while ((x = _getchar()) <= ' ');
    if ((_sign = x == '-')) x = _getchar();
    for (x -= '0'; (_c = _getchar()) >= '0'; x = x * 10 + _c - '0');
    if (_sign) x = -x;
  }
  template <class UI> void _readUnsigned(UI &x) {
    while ((x = _getchar()) <= ' ');
    for (x -= '0'; (_c = _getchar()) >= '0'; x = x * 10 + _c - '0');
  }
  template <class F> void _readFloatingPoint(F &x) {
    for (x = 0; (_c = _getchar()) <= ' ';);
    if ((_sign = _c == '-')) _c = _getchar();
    if (_c >= '0')
      for (x = _c - '0'; (_c = _getchar()) >= '0'; x = x * 10 + _c - '0');
    if (_c == '.') {
      F _div = 1.0;
      for (; (_c = _getchar()) >= '0'; x += (_c - '0') / (_div *= 10));
    }
    if (_sign) x = -x;
  }
  void setLength(int x) {
    if (_tempInputBuf) delete[](_tempInputBuf);
    _tempInputBuf = new char[x + 1];
  }
  template <class I> typename enable_if<is_integral<I>::value
      && is_signed<I>::value>::type read(I &x) { _readSigned(x); }
  template <class UI> typename enable_if<is_integral<UI>::value
      && is_unsigned<UI>::value>::type read(UI &x) {
    _readUnsignedSigned(x);
  }
#if __SIZEOF_INT128__
  void read(__int128_t &x) { _readSigned(x); }
  void read(__uint128_t &x) { _readUnsigned(x); }
#endif
  template <class F>
  typename enable_if<is_floating_point<F>::value>::type read(F &x) {
    _readFloatingPoint(x);
  }
  void read(char &x) { while ((x = _getchar()) <= ' '); }
  void read(char *x) {
    _cur = 0; do { _c = _getchar(); } while (_c <= ' ');
    do { x[_cur++] = _c; } while ((_c = _getchar()) > ' ');
    x[_cur] = '\0';
  }
  void readln(char *x) {
    if (_last == '\r') _getcharskipr();
    for (_cur = 0; (_c = _getcharskipr()) != '\n' && _c; x[_cur++] = _c);
    x[_cur] = '\0';
  }
  void read(string &x) {
    if (!_tempInputBuf) assert(0);
    read(_tempInputBuf); x = string(_tempInputBuf, _cur);
  }
  void readln(string &x) {
    if (!_tempInputBuf) assert(0);
    readln(_tempInputBuf); x = string(_tempInputBuf, _cur);
  }
  template <class T> typename enable_if<
      is_iterator<typename T::iterator>::value>::type read(T &x);
  template <class T1, class T2>
  void read(pair<T1, T2> &x) { read(x.first); read(x.second); }
  template <class T> void read(complex<T> &x) {
    T _re, _im; read(_re); read(_im); x.real(_re); x.imag(_im);
  }
  template <class T, class ...Ts> void read(T &x, Ts &&...xs);
  template <class It>
  typename enable_if<is_iterator<It>::value>::type read(It st, It en) {
    for (It _i = st; _i != en; _i++) read(*_i);
  }
  template <class It, class ...Ts>
  typename enable_if<is_iterator<It>::value>::type read(
      It st, It en, Ts &&...xs) {
    read(st, en); read(forward<Ts>(xs)...);
  }
  template <class T> typename enable_if<
      is_iterator<typename T::iterator>::value>::type read(T &x) {
    for (auto &&_i : x) read(_i);
  }
  template <class T, class...Ts> void read(T &x, Ts &&...xs) {
    read(x); read(forward<Ts>(xs)...);
  }
  void setInput(FILE *file) { *(_inputPtr = _inputBuf) = 0; _input = file; }
  void setInput(const string &s) {
    *(_inputPtr = _inputBuf) = 0; _input = fopen(s.c_str(), "r");
  }
  int _flushBuf() {
    fwrite(_outputBuf, 1, _outputPtr, _output); return _outputPtr = 0;
  }
  void flush() { _flushBuf(); fflush(_output); }
  int _putchar(char x) {
    _outputBuf[_outputPtr == _bufSize ? _flushBuf() : _outputPtr] = x;
    return _outputPtr++;
  }
  void _writeTempBuf(char x) { _tempOutputBuf[_tempOutputPtr++] = x; }
  void _writeOutput() {
    for (int _i = 0; _i < _tempOutputPtr; _putchar(_tempOutputBuf[_i++]));
    _tempOutputPtr = 0;
  }
  void _fillBuf(int x) { for (int _i = 0; _i < x; _i++) _putchar(_fill); }
  void _flushNumBuf() { for (; _numPtr; _writeTempBuf(_numBuf[--_numPtr])); }
  void _flushTempBuf() {
    int _tempLen = _tempOutputPtr; _fillBuf(_width - _tempLen);
    _writeOutput(); _fillBuf(-_width - _tempLen);
  }
  void setPrecision(int x) {
    _precision = x; _precisionBase = 1;
    for (int _i = 0; _i < x; _i++, _precisionBase *= 10);
  }
  void setWidth(int x) { _width = x; }
  void setFill(char x) { _fill = x; }
  void setDelimiter(const char *x) { _delimiter = x; }
  void setDelimiter(const string &x) { _delimiter = x.c_str(); }
  void writeDelimiter() {
    for (const char *_p = _delimiter; *_p; _putchar(*_p++));
  }
  template <class T> void _writeNum(const T &x, int digits) {
    _cnt = 0;
    for (T _y = x; _y; _y /= 10, _cnt++) _numBuf[_numPtr++] = '0' + _y % 10;
    for (; _cnt < digits; _cnt++) _numBuf[_numPtr++] = '0';
    _flushNumBuf();
  }
  template <class F> void _writeFloatingPoint(const F &x) {
    unsigned long long _I = x, _F = (x - _I) * _precisionBase + F(0.5);
    if (_F >= _precisionBase) { _I++; _F = 0; }
    _writeNum(_I, 1); _writeTempBuf('.'); _writeNum(_F, _precision);
  }
  void write(const bool &x) {
    if (x) _writeTempBuf('1');
    else _writeTempBuf('0');
    _flushTempBuf();
  }
  void write(const char &x) { _writeTempBuf(x); _flushTempBuf(); }
  void write(const char *x) {
    int _slen = strlen(x); _fillBuf(_width - _slen);
    for (const char *_p = x; *_p; _putchar(*_p++));
    _fillBuf(-_width - _slen);
  }
  void write(const string &x) {
    _fillBuf(_width - int(x.length()));
    for (int _i = 0; _i < int(x.length()); _putchar(x[_i++]));
    _fillBuf(-_width - int(x.length()));
  }
  template <class I>
  typename enable_if<is_integral<I>::value
      && is_signed<I>::value>::type write(const I &x) {
    using UI = typename make_unsigned<I>::type;
    if (x < 0) { _writeTempBuf('-'); _writeNum(UI(-x), 1); }
    else { _writeNum(UI(x), 1); }
    _flushTempBuf();
  }
  template <class UI>
  typename enable_if<is_integral<UI>::value
      && is_unsigned<UI>::value >::type write(const UI &x) {
    _writeNum(x, 1); _flushTempBuf();
  }
  template <class F>
  typename enable_if<is_floating_point<F>::value>::type write(
      const F &x) {
    if (isnan(x)) write("NaN");
    else if (isinf(x)) write("Inf");
    else if (x < 0) { _writeTempBuf('-'); _writeFloatingPoint(-x); }
    else _writeFloatingPoint(x);
    _flushTempBuf();
  }
#if __SIZEOF_INT128__
  void write(const __int128_t &x) {
    if (x < 0) { _writeTempBuf('-'); _writeNum(__uint128_t(-x), 1); }
    else _writeNum(__uint128_t(x), 1);
    _flushTempBuf();
  }
  void write(const __uint128_t &x) { _writeNum(x, 1); _flushTempBuf(); }
#endif
  template <class T> typename enable_if<
      is_iterator<typename T::iterator>::value>::type write(const T &x);
  template <class T1, class T2> void write(const pair<T1, T2> &x) {
    write(x.first); writeDelimiter(); write(x.second);
  }
  template <class T> void write(const complex<T> &x) {
    write(x.real()); writeDelimiter(); write(x.imag());
  }
  template <class T, class ...Ts> void write(const T &x, Ts &&...xs);
  template <class It>
  typename enable_if<is_iterator<It>::value>::type write(It st, It en) {
    bool _first = 1; for (It _i = st; _i != en; _i++) {
      if (_first) _first = 0;
      else writeDelimiter();
      write(*_i);
    }
  }
  template <class It, class ...Ts>
  typename enable_if<is_iterator<It>::value>::type write(
      It st, It en, Ts &&...xs) {
    write(st, en); writeDelimiter(); write(forward<Ts>(xs)...);
  }
  template <class T> typename enable_if<
      is_iterator<typename T::iterator>::value>::type write(const T &x) {
    bool _first = 1; for (auto &&_i : x) {
      if (_first) _first = 0;
      else writeDelimiter();
      write(_i);
    }
  }
  template <class T, class ...Ts> void write(const T &x, Ts &&...xs) {
    write(x); writeDelimiter(); write(forward<Ts>(xs)...);
  }
  void writeln() { _putchar('\n'); }
  template <class ...Ts>
  void writeln(Ts &&...xs) { write(forward<Ts>(xs)...); _putchar('\n'); }
  struct IOManager {
    ~IOManager() { flush(); if (_tempInputBuf) delete[](_tempInputBuf); }
  };
  unique_ptr<IOManager> iomanager = unique_ptr<IOManager>(
      new IOManager());
  void setOutput(FILE *file) { flush(); _output = file; }
  void setOutput(const string &s) {
    flush(); _output = fopen(s.c_str(), "w");
  }
  template <class ...Ts> void debug(Ts &&...xs) {
    FILE *_temp = _output; setOutput(_error);
    write(forward<Ts>(xs)...); setOutput(_temp);
  }
  template <class...Ts> void debugln(Ts &&...xs) {
    FILE *_temp = _output; setOutput(_error);
    writeln(forward<Ts>(xs)...); setOutput(_temp);
  }
  void setError(FILE *file) { flush(); _error = file; }
  void setError(const string &s) {
    flush(); _error = fopen(s.c_str(), "w");
  }
struct BitFenwickTree {
  int N, M; vector<uint64_t> mask; vector<int> BIT;
  BitFenwickTree(int N) : N(N), M((N >> 6) + 1), mask(M, 0), BIT(M + 1, 0) {}
  void set(int i, bool v) {
    int j = i >> 6, k = i & 63;
    mask[j] = (mask[j] & ~(uint64_t(1) << k)) | (uint64_t(v) << k);
  }
  bool get(int i) { return (mask[i >> 6] >> (i & 63)) & 1; }
  void build() {
    for (int i = 1; i <= M; i++) {
      BIT[i] += __builtin_popcountll(mask[i - 1]); int j = i + (i & -i);
      if (j <= M) BIT[j] += BIT[i];
    }
  }
  void update(int i, bool v) {
    int j = i >> 6, k = i & 63; if (((mask[j] >> k) & 1) != v) {
      mask[j] ^= uint64_t(1) << k; int delta = v ? 1 : -1;
      for (j++; j <= M; j += j & -j) BIT[j] += delta;
    }
  }
  int query(int r) {
    r++; int j = r >> 6, k = r & 63, ret = 0;
    for (int i = j; i > 0; i -= i & -i) ret += BIT[i];
    return ret + __builtin_popcountll(mask[j] & ((uint64_t(1) << k) - 1));
  }
  int query(int l, int r) { return query(r) - query(l - 1); }
  template <class F> int bsearch(int v, F cmp) {
    int sum = 0, ind = 0; for (int j = __lg(M + 1); j >= 0; j--) {
      int i = ind + (1 << j);
      if (i <= M && cmp(sum + BIT[i], v)) sum += BIT[ind = i];
    }
    if (ind == M) return N;
    uint64_t m = mask[ind]; ind <<= 6;
    for (;; ind++, m >>= 1) if (!cmp(sum += m & 1, v)) break;
    return ind;
  }
};
template <const int D, class T, class Op = plus<T>, class Inv = minus<T>>
struct FenwickTree {
  int N; vector<FenwickTree<D - 1, T, Op, Inv>> BIT; T val;
  template <class ...Args> FenwickTree(int N, Args &&...args)
      : N(N),
        BIT(N + 1, FenwickTree<D - 1, T, Op, Inv>(forward<Args>(args)...)),
        val(BIT[0].val) {}
  template <class ...Args> void update(int i, Args &&...args) {
    for (i++; i <= N; i += i & -i) BIT[i].update(forward<Args>(args)...);
  }
  template <class ...Args> T queryPrefix(int r, Args &&...args) {
    T ret = val; for (r++; r > 0; r -= r & -r)
      ret = Op()(ret, BIT[r].queryPrefix(forward<Args>(args)...));
    return ret;
  }
  template <class ...Args> T query(int l, int r, Args &&...args) {
    T ret = val; for (; l > 0; l -= l & -l)
      ret = Inv()(ret, BIT[l].query(forward<Args>(args)...));
    for (r++; r > 0; r -= r & -r)
      ret = Op()(ret, BIT[r].query(forward<Args>(args)...));
    return ret;
  }
};

template <class T, class Op, class Inv> struct FenwickTree<0, T, Op, Inv> {
  T val; FenwickTree(T qdef = T()) : val(qdef) {}
  void update(T v) { val = Op()(val, v); }
  T queryPrefix() { return val; }
  T query() { return val; }
};
#undef INTERACTIVE_INPUT
}

template <class T> struct NodeVal {
  using Data = T; using Lazy = Data;
  static const bool RANGE_UPDATES = false, RANGE_QUERIES = false;
  static const bool RANGE_REVERSALS = true;
  bool rev; int sz; NodeVal *l, *r, *p; Data val;
  NodeVal(const Data &v)
      : rev(false), sz(1), l(nullptr), r(nullptr), p(nullptr), val(v) {}
  void update() {
    sz = 1;
    if (l) sz += l->sz;
    if (r) sz += r->sz;
  }
  void propagate() {
    if (rev) {
      if (l) l->reverse();
      if (r) r->reverse();
      rev = false;
    }
  }
  void apply(const Lazy &v) { val = v; }
  void reverse() { rev = !rev; swap(l, r); }
};

template <class C> struct NodeAgg {
  using Data = typename C::Data; using Lazy = typename C::Lazy;
  static const bool RANGE_UPDATES = false, RANGE_QUERIES = true;
  static const bool RANGE_REVERSALS = true;
  bool rev; int sz; NodeAgg *l, *r, *p; Data val, sbtr;
  NodeAgg(const Data &v)
      : rev(false), sz(1), l(nullptr), r(nullptr), p(nullptr),
        val(v), sbtr(v) {}
  void update() {
    sz = 1; sbtr = val;
    if (l) { sz += l->sz; sbtr = C::merge(l->sbtr, sbtr); }
    if (r) { sz += r->sz; sbtr = C::merge(sbtr, r->sbtr); }
  }
  void propagate() {
    if (rev) {
      if (l) l->reverse();
      if (r) r->reverse();
      rev = false;
    }
  }
  void apply(const Lazy &v) {
    val = C::applyLazy(val, v); sbtr = C::applyLazy(sbtr, v);
  }
  void reverse() { rev = !rev; swap(l, r); C::revData(sbtr); }
  static Data qdef() { return C::qdef(); }
};

template <class C> struct NodeLazyAgg {
  using Data = typename C::Data; using Lazy = typename C::Lazy;
  static const bool RANGE_UPDATES = true, RANGE_QUERIES = true;
  static const bool RANGE_REVERSALS = true;
  bool rev; int sz; NodeLazyAgg *l, *r, *p; Lazy lz; Data val, sbtr;
  NodeLazyAgg(const Data &v)
      : rev(false), sz(1), l(nullptr), r(nullptr), p(nullptr),
        lz(C::ldef()), val(v), sbtr(v) {}
  void update() {
    sz = 1; sbtr = val;
    if (l) { sz += l->sz; sbtr = C::merge(l->sbtr, sbtr); }
    if (r) { sz += r->sz; sbtr = C::merge(sbtr, r->sbtr); }
  }
  void propagate() {
    if (rev) {
      if (l) l->reverse();
      if (r) r->reverse();
      rev = false;
    }
    if (lz != C::ldef()) {
      if (l) l->apply(lz);
      if (r) r->apply(lz);
      lz = C::ldef();
    }
  }
  void apply(const Lazy &v) {
    lz = C::mergeLazy(lz, v); val = C::applyLazy(val, v, 1);
    sbtr = C::applyLazy(sbtr, v, sz);
  }
  void reverse() { rev = !rev; swap(l, r); C::revData(sbtr); }
  static Data qdef() { return C::qdef(); }
};

template <class T, class Op> struct SparseTable {
  int N; vector<vector<T>> ST; Op op;
  SparseTable(vector<T> A, Op op = Op())
      : N(A.size()), ST(N == 0 ? 0 : __lg(N) + 1, move(A)), op(op) {
    for (int i = 0; i < int(ST.size()) - 1; i++) {
      ST[i + 1] = ST[0]; for (int j = 0; j < N; j++)
        ST[i + 1][j] = op(ST[i][j], ST[i][min(j + (1 << i), N - 1)]);
    }
  }
  T query(int l, int r) {
    int i = __lg(r - l + 1); return op(ST[i][l], ST[i][r - (1 << i) + 1]);
  }
};

template <class T, class Op> struct SegmentTree {
  int N; vector<T> ST; Op op;
  SegmentTree(int N, Op op = Op()) : N(N), ST(2 * N, op.qdef()), op(op) {}
  SegmentTree(vector<T> A, Op op = Op())
      : N(A.size()), ST(2 * N, op.qdef()), op(op) {
    copy(A.begin(), A.end(), ST.begin() + N);
    for (int i = N - 1; i > 0; i--) ST[i] = op(ST[i << 1], ST[i << 1 | 1]);
  }
  void update(int i, T v) {
    for (ST[i += N] = v; i >>= 1; )
      ST[i] = op(ST[i << 1], ST[i << 1 | 1]);
  }
  T query(int l, int r) {
    T retl = op.qdef(), retr = op.qdef();
    for (l += N, r += N + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) retl = op(retl, ST[l++]);
      if (r & 1) retr = op(ST[--r], retr);
    }
    return op(retl, retr);
  }
};

template <class T, class Cmp = less<T>> struct WaveletMatrix {
#define clt [&] (const T &a, const T &b) { return cmp(a, b); }
#define cle [&] (const T &a, const T &b) { return !cmp(b, a); }
  int N, H; Cmp cmp; vector<int> mid; vector<BitPrefixSumArray> B; vector<T> S;
  WaveletMatrix(vector<T> A, Cmp cmp = Cmp())
      : N(A.size()), H(N == 0 ? 0 : __lg(N) + 1), cmp(cmp), mid(H),
        B(H, BitPrefixSumArray(N)), S(move(A)) {
    vector<T> temp = S; sort(S.begin(), S.end(), cmp); vector<int> C(N);
    for (int i = 0; i < N; i++)
      C[i] = lower_bound(S.begin(), S.end(), temp[i], cmp) - S.begin();
    for (int h = H - 1; h >= 0; h--) {
      int ph = 1 << h; for (int i = 0; i < N; i++) B[h].set(i, C[i] <= ph - 1);
      mid[h] = stable_partition(C.begin(), C.end(), [&] (int v) {
                                  return v <= ph - 1;
                                }) - C.begin();
      B[h].build(); for (int i = mid[h]; i < N; i++) C[i] -= ph;
    }
  }
  template <class F> int cnt(int l, int r, const T &v, F f) {
    int ret = 0; for (int cur = 0, h = H - 1; h >= 0; h--) {
      int ph = 1 << h, ql = B[h].query(l - 1), qr = B[h].query(r);
      if (cur + ph - 1 >= N || f(v, S[cur + ph - 1])) { l = ql; r = qr - 1; }
      else { cur += ph; ret += qr - ql; l += mid[h] - ql; r += mid[h] - qr; }
    }
    return ret;
  }
  int rank(int l, int r, const T &v) { return cnt(l, r, v, cle); }
  int count(int l, int r, const T &lo, const T &hi) {
    return cnt(l, r, hi, clt) - cnt(l, r, lo, cle);
  }
  T select(int l, int r, int k) {
    int cur = 0; for (int h = H - 1; h >= 0; h--) {
      int ql = B[h].query(l - 1), qr = B[h].query(r);
      if (k < qr - ql) { l = ql; r = qr - 1; }
      else { cur += 1 << h; k -= qr - ql; l += mid[h] - ql; r += mid[h] - qr; }
    }
    return S[cur];
  }
#undef clt
#undef cle
};

template <class W>
vector<W> boundedKnapsackDual(const vector<tuple<W, int, int>> &A, int K,
                              W INF = numeric_limits<W>::max()) {
  vector<W> dp(K + 1, INF), q(K + 1, W()), dq(K + 1, W()); dp[0] = W();
  for (auto &&a : A) {
    int v = get<1>(a), f = get<2>(a); W w = get<0>(a);
    if (v <= K) for (int s = 0; s < v; s++) {
      W alpha = W(); int ql = 0, qr = 0, dql = 0, dqr = 0;
      for (int j = s; j <= K; j += v) {
        alpha += w; W a = dp[j] >= INF ? INF : dp[j] - alpha;
        while (dql < dqr && dq[dqr - 1] > a) dqr--;
        q[qr++] = dq[dqr++] = a;
        while (qr - ql > f + 1) if (q[ql++] == dq[dql]) dql++;
        dp[j] = dq[dql] >= INF ? INF : dq[dql] + alpha;
      }
    }
  }
  return dp;
}

template <class V>
vector<V> boundedKnapsack(const vector<tuple<int, V, int>> &A, int M,
                          V NEG_INF = numeric_limits<V>::lowest()) {
  vector<V> dp(M + 1, NEG_INF), q(M + 1, V()), dq(M + 1, V()); dp[0] = V();
  for (auto &&a : A) {
    int w = get<0>(a), f = get<2>(a); V v = get<1>(a);
    if (w <= M) for (int s = 0; s < w; s++) {
      V alpha = V(); int ql = 0, qr = 0, dql = 0, dqr = 0;
      for (int j = s; j <= M; j += w) {
        alpha += v; V a = dp[j] <= NEG_INF ? NEG_INF : dp[j] - alpha;
        while (dql < dqr && dq[dqr - 1] < a) dqr--;
        q[qr++] = dq[dqr++] = a;
        while (qr - ql > f + 1) if (q[ql++] == dq[dql]) dql++;
        dp[j] = dq[dql] <= NEG_INF ? NEG_INF : dq[dql] + alpha;
      }
    }
  }
  return dp;
}

template <class T> tuple<T, int, int> maxSubarraySum(
    const vector<T> &A, T NEG_INF = numeric_limits<T>::lowest()) {
  tuple<T, int, int> ret = make_tuple(NEG_INF, 0, -1); T sm = T();
  for (int i = 0, l = 0; i < int(A.size()); i++) {
    sm += A[i]; if (get<0>(ret) < sm) ret = make_tuple(sm, l, i);
    if (sm < T()) { sm = T(); l = i + 1; }
  }
  return ret;
}

template <class T, class HTYPE, const int HASHES> struct Hashing {
  using arr = array<HTYPE, HASHES>; int N; arr BASE, MOD; vector<arr> H, POW;
  struct HASH : public arr { int len; };
  Hashing(const vector<T> &S, T offset, const arr &BASE, const arr &MOD)
      : N(S.size()), BASE(BASE), MOD(MOD), H(N + 1), POW(N + 1) {
    POW[0].fill(HTYPE(1)); H[N].fill(HTYPE());
    for (int i = 1; i <= N; i++) for (int h = 0; h < HASHES; h++)
      POW[i][h] = mulMod(POW[i - 1][h], BASE[h], MOD[h]);
    for (int i = N - 1; i >= 0; i--) for (int h = 0; h < HASHES; h++)
      H[i][h] = addMod(mulMod(H[i + 1][h], BASE[h], MOD[h]),
                       posMod(HTYPE(S[i] - offset) + HTYPE(1), MOD[h]),
                       MOD[h]);
  }
  static arr initBase(const arr &MOD) {
    arr base;
    for (int h = 0; h < HASHES; h++) base[h] = uniform_int_distribution<HTYPE>(
        MOD[h] / 4, MOD[h] / 4 * 3)(rng64);
    return base;
  }
  Hashing(const vector<T> &S, T offset, const arr &MOD)
      : Hashing(S, offset, initBase(MOD), MOD) {}
  HASH getHash(int l, int r) {
    HASH ret; ret.len = ++r - l; for (int h = 0; h < HASHES; h++)
      ret[h] = subMod(H[l][h], mulMod(H[r][h], POW[r - l][h], MOD[h]), MOD[h]);
    return ret;
  }
  HASH merge(const HASH &h1, const HASH &h2) {
    HASH ret; ret.len = h1.len + h2.len; for (int h = 0; h < HASHES; h++)
      ret[h] = addMod(h1[h], mulMod(h2[h], POW[h1.len][h], MOD[h]), MOD[h]);
    return ret;
  }
  HASH concat(int l1, int r1, int l2, int r2) {
    return merge(getHash(l1, r1), getHash(l2, r2));
  }
};

template <class Node> struct LCT : public Splay<Node, vector<Node>> {
  using Tree = Splay<Node, vector<Node>>;
  using Tree::TR; using Tree::makeNode; using Tree::splay; using Tree::select;
  using Data = typename Node::Data; using Lazy = typename Node::Lazy;
  int vert(Node *x) { return x - TR.data(); }
  Node *access(Node *x) {
    Node *last = nullptr;
    for (Node *y = x; y; y = y->p) { splay(y); y->r = last; last = y; }
    splay(x); return last;
  }
  template <const int _ = Node::RANGE_REVERSALS>
  typename enable_if<_>::type makeRoot(Node *x) { access(x); x->reverse(); }
  Node *findMin(Node *x) {
    for (x->propagate(); x->l; (x = x->l)->propagate());
    splay(x); return x;
  }
  Node *findMax(Node *x) {
    for (x->propagate(); x->r; (x = x->r)->propagate());
    splay(x); return x;
  }
  template <const int _ = Node::RANGE_REVERSALS>
  typename enable_if<_>::type makeRoot(int x) { makeRoot(&TR[x]); }
  int lca(int x, int y) {
    if (x == y) return x;
    access(&TR[x]); Node *ny = access(&TR[y]); return TR[x].p ? vert(ny) : -1;
  }
  bool connected(int x, int y) { return lca(x, y) != -1; }
  template <const int _ = Node::RANGE_REVERSALS>
  typename enable_if<_>::type link(int x, int y) {
    makeRoot(y); TR[y].p = &TR[x];
  }
  template <const int _ = Node::RANGE_REVERSALS>
  typename enable_if<_, bool>::type safeLink(int x, int y) {
    if (connected(x, y)) return false;
    link(x, y); return true;
  }
  bool linkParent(int par, int ch) {
    access(&TR[ch]); if (TR[ch].l) return false;
    TR[ch].p = &TR[par]; return true;
  }
  template <const int _ = Node::RANGE_REVERSALS>
  typename enable_if<_, bool>::type cut(int x, int y) {
    makeRoot(x); access(&TR[y]);
    if (&TR[x] != TR[y].l || TR[x].r) return false;
    TR[y].l->p = nullptr; TR[y].l = nullptr; return true;
  }
  bool cutParent(int x) {
    access(&TR[x]); if (!TR[x].l) return false;
    TR[x].l->p = nullptr; TR[x].l = nullptr; return true;
  }
  int findParent(int x) {
    access(&TR[x]); return TR[x].l ? vert(findMax(TR[x].l)) : -1;
  }
  int findRoot(int x) { access(&TR[x]); return vert(findMin(&TR[x])); }
  int depth(int x) { access(&TR[x]); return TR[x].l ? TR[x].l->sz : 0; }
  int kthParent(int x, int k) {
    int d = depth(x); Node *nx = &TR[x];
    return k <= d ? vert(select(nx, d - k)) : -1;
  }
  void updateVertex(int x, const Lazy &v) {
    access(&TR[x]); Node *l = TR[x].l; TR[x].l = nullptr;
    TR[x].apply(v); TR[x].propagate(); TR[x].update(); TR[x].l = l;
  }
  template <const int _ = Node::RANGE_UPDATES>
  typename enable_if<_>::type updatePathFromRoot(int to, const Lazy &v) {
    access(&TR[to]); TR[to].apply(v);
  }
  template <const int _ = Node::RANGE_UPDATES && Node::RANGE_REVERSALS>
  typename enable_if<_, bool>::type updatePath(
      int from, int to, const Lazy &v) {
    makeRoot(from); access(&TR[to]);
    if (from != to && !TR[from].p) return false;
    TR[to].apply(v); return true;
  }
  Data queryVertex(int x) { access(&TR[x]); return TR[x].val; }
  template <const int _ = Node::RANGE_QUERIES>
  typename enable_if<_, Data>::type queryPathFromRoot(int to) {
    access(&TR[to]); return TR[to].sbtr;
  }
  template <const int _ = Node::RANGE_QUERIES && Node::RANGE_REVERSALS>
  typename enable_if<_, Data>::type queryPath(int from, int to) {
    makeRoot(from); access(&TR[to]);
    return from == to || TR[from].p ? TR[to].sbtr : Node::qdef();
  }
  LCT(const vector<Data> &A) {
    TR.reserve(A.size()); for (auto &&a : A) makeNode(a);
  }
};

template <class C> struct TopTree {
  using Data = typename C::Data; using Lazy = typename C::Lazy;
  struct Node {
    bool rev, aux; int szpath, szvtr; array<Node *, 4> ch; Node *p;
    Lazy lzpath, lzvtr; Data val, path, vtr;
    Node(bool aux, const Data &v)
        : rev(false), aux(aux), szpath(aux ? 0 : 1), szvtr(0),
          p(nullptr), lzpath(C::ldef()), lzvtr(C::ldef()), val(v),
          path(aux ? C::qdef() : v), vtr(C::qdef()) {
      ch.fill(nullptr);
    }
    void applyVal(const Lazy &v) { val = C::applyLazy(val, v, 1); }
    void applyPath(const Lazy &v) {
      applyVal(v); lzpath = C::mergeLazy(lzpath, v);
      if (szpath > 0) path = C::applyLazy(path, v, szpath);
    }
    void applyVtr(const Lazy &v, bool ap = true) {
      lzvtr = C::mergeLazy(lzvtr, v);
      if (szvtr > 0) vtr = C::applyLazy(vtr, v, szvtr);
      if (!aux && ap) applyPath(v);
    }
    void update() {
      szpath = aux ? 0 : 1; path = aux ? C::qdef() : val;
      szvtr = 0; vtr = C::qdef(); for (int i = 0; i < 4; i++) if (ch[i]) {
        vtr = C::merge(vtr, ch[i]->vtr); szvtr += ch[i]->szvtr; if (i < 2) {
          path = i ? C::merge(path, ch[i]->path) : C::merge(ch[i]->path, path);
          szpath += ch[i]->szpath;
        } else { vtr = C::merge(vtr, ch[i]->path); szvtr += ch[i]->szpath; }
      }
    }
    void propagate() {
      if (rev) {
        for (int i = 0; i < 2; i++) if (ch[i]) ch[i]->reverse();
        rev = false;
      }
      if (lzpath != C::ldef() && !aux) {
        for (int i = 0; i < 2; i++) if (ch[i]) ch[i]->applyPath(lzpath);
        lzpath = C::ldef();
      }
      if (lzvtr != C::ldef()) {
        for (int i = 0; i < 4; i++) if (ch[i]) ch[i]->applyVtr(lzvtr, i >= 2);
        lzvtr = C::ldef();
      }
    }
    void reverse() { rev = !rev; swap(ch[0], ch[1]); C::revData(path); }
  };
  vector<Node> TR; vector<Node *> deleted, stk;
  Node *makeNode(bool aux, const Data &v) {
    if (deleted.empty()) { TR.emplace_back(aux, v); return &TR.back(); }
    Node *x = deleted.back(); deleted.pop_back(); *x = Node(aux, v); return x;
  }
  int vert(Node *x) { return x - TR.data(); }
  bool isRoot(Node *x, bool t) {
    if (t) return !x->p || !x->aux || !x->p->aux;
    else return !x->p || (x != x->p->ch[0] && x != x->p->ch[1]);
  }
  void connect(Node *x, Node *p, int i) {
    if (x) x->p = p;
    if (i != -1) p->ch[i] = x;
  }
  int findInd(Node *x) {
    for (int i = 0; i < 4; i++) if (x->p->ch[i] == x) return i;
    return -1;
  }
  void rotate(Node *x, int t) {
    Node *p = x->p, *g = p->p; bool isL = x == p->ch[t];
    if (g) connect(x, g, findInd(p));
    else x->p = nullptr;
    connect(x->ch[t ^ isL], p, t ^ !isL); connect(p, x, t ^ isL);
    p->update();
  }
  void splay(Node *x, int t) {
    while (!isRoot(x, t)) {
      Node *p = x->p, *g = p->p;
      if (!isRoot(p, t)) rotate((x == p->ch[t]) == (p == g->ch[t]) ? p : x, t);
      rotate(x, t);
    }
    x->update();
  }
  Node *select(Node *&root, int k) {
    Node *last = nullptr; while (root) {
      (last = root)->propagate();
      int t = root->ch[0] ? root->ch[0]->szpath : 0;
      if (t > k) root = root->ch[0];
      else if (t < k) { root = root->ch[1]; k -= t + 1; }
      else break;
    }
    if (last) splay(root = last, 0);
    return root;
  }
  void add(Node *x, Node *y) {
    Node *z = makeNode(true, C::qdef());
    connect(y->ch[2], z, 2); connect(x, z, 3); connect(z, y, 2); z->update();
  }
  void rem(Node *x) {
    Node *p = x->p, *g = p->p; connect(p->ch[findInd(x) ^ 1], g, findInd(p));
    splay(g, 2); deleted.push_back(x->p); x->p = nullptr;
  }
  void touch(Node *x) {
    for (Node *y = x; y->p; y = y->p) stk.push_back(y->p);
    for (; !stk.empty(); stk.pop_back()) stk.back()->propagate();
    x->propagate();
  }
  Node *nextChain(Node *x) {
    splay(x, 0); if (!x->p) return nullptr;
    Node *p = x->p; splay(p, 2); return p->p;
  }
  Node *access(Node *x) {
    touch(x); Node *last = nullptr; for (Node *y = x; y; y = nextChain(y)) {
      splay(y, 0); if (last) rem(last);
      if (y->ch[1]) add(y->ch[1], y);
      connect(last, y, 1); last = y;
    }
    splay(x, 0); return last;
  }
  void makeRoot(Node *x) { access(x); x->reverse(); }
  Node *findMin(Node *x) {
    for (x->propagate(); x->ch[0]; (x = x->ch[0])->propagate());
    splay(x, 0); return x;
  }
  Node *findMax(Node *x) {
    for (x->propagate(); x->ch[1]; (x = x->ch[1])->propagate());
    splay(x, 0); return x;
  }
  void makeRoot(int x) { makeRoot(&TR[x]); }
  int lca(int x, int y) {
    if (x == y) return x;
    access(&TR[x]); Node *ny = access(&TR[y]); return TR[x].p ? vert(ny) : -1;
  }
  bool connected(int x, int y) { return lca(x, y) != -1; }
  void link(int par, int ch) {
    makeRoot(par); access(&TR[ch]); add(&TR[par], &TR[ch]);
  }
  bool safeLink(int par, int ch) {
    if (connected(par, ch)) return false;
    link(par, ch); return true;
  }
  bool cutParent(int x) {
    access(&TR[x]); if (!TR[x].ch[0]) return false;
    TR[x].ch[0]->p = nullptr; TR[x].ch[0] = nullptr; return true;
  }
  int findParent(int x) {
    access(&TR[x]); return TR[x].ch[0] ? vert(findMax(TR[x].ch[0])) : -1;
  }
  int findRoot(int x) { access(&TR[x]); return vert(findMin(&TR[x])); }
  int depth(int x) {
    access(&TR[x]); return TR[x].ch[0] ? TR[x].ch[0]->szpath : 0;
  }
  int kthParent(int x, int k) {
    int d = depth(x); Node *nx = &TR[x];
    return k <= d ? vert(select(nx, d - k)) : -1;
  }
  void updateVertex(int x, const Lazy &v) {
    access(&TR[x]); TR[x].applyVal(v); TR[x].update();
  }
  void updatePathFromRoot(int to, const Lazy &v) {
    access(&TR[to]); TR[to].applyPath(v);
  }
  bool updatePath(int from, int to, const Lazy &v) {
    makeRoot(from); access(&TR[to]);
    if (from != to && !TR[from].p) return false;
    TR[to].applyPath(v); return true;
  }
  void updateSubtree(int x, const Lazy &v) {
    access(&TR[x]); TR[x].applyVal(v);
    for (int i = 2; i < 4; i++) if (TR[x].ch[i]) TR[x].ch[i]->applyVtr(v);
  }
  Data queryVertex(int x) { access(&TR[x]); return TR[x].val; }
  Data queryPathFromRoot(int to) { access(&TR[to]); return TR[to].sbtr; }
  Data queryPath(int from, int to) {
    makeRoot(from); access(&TR[to]);
    return from == to || TR[from].p ? TR[to].path : C::qdef();
  }
  Data querySubtree(int x) {
    access(&TR[x]); Data ret = TR[x].val;
    for (int i = 2; i < 4; i++) if (TR[x].ch[i]) {
      ret = C::merge(C::merge(ret, TR[x].ch[i]->vtr), TR[x].ch[i]->path);
    }
    return ret;
  }
  TopTree(const vector<Data> &A) {
    TR.reserve(A.size() * 2); for (auto &&a : A) makeNode(false, a);
  }
};

template <class T = int> struct BFS {
  using Edge = tuple<int, int, T>; vector<T> dist; vector<int> par; T INF;
  int getTo(int e) { return e; }
  T getWeight(int) { return 1; }
  int getTo(const pair<int, T> &e) { return e.first; }
  T getWeight(const pair<int, T> &e) { return e.second; }
  template <class Graph> BFS(const Graph &G, const vector<int> &srcs,
                             T INF = numeric_limits<T>::max())
      : dist(G.size(), INF), par(G.size(), -1), INF(INF) {
    vector<int> q(G.size()); int front = 0, back = 0;
    for (int s : srcs) dist[q[back++] = s] = T();
    while (front < back) {
      int v = q[front++]; for (auto &&e : G[v]) {
        int w = getTo(e); if (dist[w] >= INF)
          dist[q[back++] = w] = dist[par[w] = v] + getWeight(e);
      }
    }
  }
  template <class Graph> BFS(const Graph &G, int s,
                             T INF = numeric_limits<T>::max())
      : BFS(G, vector<int>{s}, INF) {}
  vector<Edge> getPath(int v) {
    vector<Edge> path; for (; par[v] != -1; v = par[v])
      path.emplace_back(par[v], v, dist[v] - dist[par[v]]);
    reverse(path.begin(), path.end()); return path;
  }
};

struct DFSOrder {
  int V, curPre, curPost, curRevPost;
  vector<int> preInd, postInd, revPostInd, preVert, postVert, revPostVert;
  template <class Graph> void dfs(const Graph &G, int v) {
    preVert[preInd[v] = curPre++] = v;
    for (int w : G[v]) if (preInd[w] == -1) dfs(G, w);
    postVert[postInd[v] = curPost++] = v;
    revPostVert[revPostInd[v] = curRevPost--] = v;
  }
  template <class Graph>
  DFSOrder(const Graph &G, const vector<int> &roots = vector<int>())
      : V(G.size()), curPre(0), curPost(0), curRevPost(V - 1), preInd(V, -1),
        postInd(V), revPostInd(V), preVert(V), postVert(V), revPostVert(V) {
    if (roots.empty()) {
      for (int v = 0; v < V; v++) if (preInd[v] == -1) dfs(G, v);
    } else for (int v : roots) if (preInd[v] == -1) dfs(G, v);
  }
  template <class Graph> DFSOrder(const Graph &G, int rt)
      : DFSOrder(G, vector<int>{rt}) {}
};

template <class T> struct DijkstraSSSP {
  using Edge = tuple<int, int, T>; vector<T> dist; vector<int> par; T INF;
  struct Node {
    T d; int v; Node(T d, int v) : d(d), v(v) {}
    bool operator < (const Node &o) const { return d > o.d; }
  };
  template <class WeightedGraph>
  DijkstraSSSP(const WeightedGraph &G, const vector<int> &srcs,
               T INF = numeric_limits<T>::max())
      : dist(G.size(), INF), par(G.size(), -1), INF(INF) {
    std::priority_queue<Node> PQ;
    for (int s : srcs) PQ.emplace(dist[s] = T(), s);
    while (!PQ.empty()) {
      T d = PQ.top().d; int v = PQ.top().v; PQ.pop();
      if (d > dist[v]) continue;
      for (auto &&e : G[v]) if (dist[e.first] > dist[v] + e.second)
        PQ.emplace(dist[e.first] = dist[par[e.first] = v] + e.second, e.first);
    }
  }
  template <class WeightedGraph> DijkstraSSSP(const WeightedGraph &G, int s,
                                              T INF = numeric_limits<T>::max())
      : DijkstraSSSP(G, vector<int>{s}, INF) {}
  vector<Edge> getPath(int v) {
    vector<Edge> path; for (; par[v] != -1; v = par[v])
      path.emplace_back(par[v], v, dist[v] - dist[par[v]]);
    reverse(path.begin(), path.end()); return path;
  }
};

int main(){
  boost;
  return 0;
}
