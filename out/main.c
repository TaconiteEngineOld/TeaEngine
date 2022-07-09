/* ------------------------------ DIRECTIVES -------------------------------- */
/* Disable some warnings that the generated code can trigger. */
#if defined(__clang__) && __clang_major__ >= 3
  #pragma clang diagnostic ignored "-Wtype-limits"
  #pragma clang diagnostic ignored "-Wwrite-strings"
  #pragma clang diagnostic ignored "-Wunused"
  #pragma clang diagnostic ignored "-Wunused-parameter"
  #pragma clang diagnostic ignored "-Wmissing-field-initializers"
  #pragma clang diagnostic ignored "-Wparentheses-equality"
  #pragma clang diagnostic ignored "-Wtautological-compare"
  #ifndef __cplusplus
    #pragma clang diagnostic ignored "-Wmissing-braces"
    #pragma clang diagnostic ignored "-Wincompatible-pointer-types"
    #pragma clang diagnostic error   "-Wimplicit-function-declaration"
    #pragma clang diagnostic error   "-Wimplicit-int"
  #else
    #pragma clang diagnostic ignored "-Wnarrowing"
  #endif
#elif defined(__GNUC__) && __GNUC__ >= 5
  #pragma GCC diagnostic ignored "-Wtype-limits"
  #pragma GCC diagnostic ignored "-Wwrite-strings"
  #pragma GCC diagnostic ignored "-Wunused-parameter"
  #pragma GCC diagnostic ignored "-Wunused-value"
  #pragma GCC diagnostic ignored "-Wunused-variable"
  #pragma GCC diagnostic ignored "-Wunused-function"
  #pragma GCC diagnostic ignored "-Wunused-but-set-variable"
  #pragma GCC diagnostic ignored "-Wmissing-field-initializers"
  #ifndef __cplusplus
    #pragma GCC diagnostic ignored "-Wmissing-braces"
    #pragma GCC diagnostic ignored "-Wincompatible-pointer-types"
    #pragma GCC diagnostic ignored "-Wdiscarded-qualifiers"
    #pragma GCC diagnostic error   "-Wimplicit-function-declaration"
    #pragma GCC diagnostic error   "-Wimplicit-int"
  #else
    #pragma GCC diagnostic ignored "-Wnarrowing"
  #endif
#endif
#if defined(_WIN32) && !defined(_CRT_SECURE_NO_WARNINGS)
  #define _CRT_SECURE_NO_WARNINGS
#endif
/* Macro used to perform compile-time checks. */
#if __STDC_VERSION__ >= 201112L
  #define NELUA_STATIC_ASSERT _Static_assert
#elif __cplusplus >= 201103L
  #define NELUA_STATIC_ASSERT static_assert
#else
  #define NELUA_STATIC_ASSERT(x, y)
#endif
/* Macro used to get alignment of a type. */
#if __STDC_VERSION__ >= 201112L
  #define NELUA_ALIGNOF _Alignof
#elif __cplusplus >= 201103L
  #define NELUA_ALIGNOF alignof
#elif defined(__GNUC__)
  #define NELUA_ALIGNOF __alignof__
#elif defined(_MSC_VER)
  #define NELUA_ALIGNOF __alignof
#else
  #define NELUA_ALIGNOF(x)
#endif
/* Checks if Nelua and C agrees on pointer size. */
NELUA_STATIC_ASSERT(sizeof(void*) == 8 && NELUA_ALIGNOF(void*) == 8, "Nelua and C disagree on pointer size or alignment");
/* Enable 64 bit offsets for stdio APIs. */
#if !defined(_FILE_OFFSET_BITS) && __SIZEOF_LONG__ >= 8
  #define _FILE_OFFSET_BITS 64
#endif
/* Enable POSIX APIs in included headers. */
#if !defined(_POSIX_C_SOURCE) && !defined(_XOPEN_SOURCE) && !defined(_GNU_SOURCE) && !defined(_DEFAULT_SOURCE)
  #if defined(__gnu_linux__)
    #define _GNU_SOURCE
  #else
    #define _XOPEN_SOURCE 600
  #endif
#endif
#define NELUA_NIL (nlniltype){}
#include <string.h>
/* Macro used to force inlining a function. */
#ifdef __GNUC__
  #define NELUA_INLINE __attribute__((always_inline)) inline
#elif defined(_MSC_VER)
  #define NELUA_INLINE __forceinline
#elif __STDC_VERSION__ >= 199901L
  #define NELUA_INLINE inline
#else
  #define NELUA_INLINE
#endif
#include <stdint.h>
/* Macro used for branch prediction. */
#if defined(__GNUC__) || defined(__clang__)
  #define NELUA_UNLIKELY(x) __builtin_expect(x, 0)
#else
  #define NELUA_UNLIKELY(x) (x)
#endif
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/* Macro used to import/export extern C functions. */
#ifdef __cplusplus
  #define NELUA_EXTERN extern "C"
#else
  #define NELUA_EXTERN extern
#endif
/* Macro used to generate traceback on aborts when sanitizing. */
#if defined(__clang__) && defined(__has_feature)
  #if __has_feature(undefined_behavior_sanitizer)
    #define NELUA_UBSAN_UNREACHABLE __builtin_unreachable
  #endif
#elif defined(__gnu_linux__) && defined(__GNUC__) && __GNUC__ >= 5
  NELUA_EXTERN void __ubsan_handle_builtin_unreachable(void*) __attribute__((weak));
  #define NELUA_UBSAN_UNREACHABLE() {if(&__ubsan_handle_builtin_unreachable) __builtin_unreachable();}
#endif
#ifndef NELUA_UBSAN_UNREACHABLE
  #define NELUA_UBSAN_UNREACHABLE()
#endif
/* Macro used to specify a function that never returns. */
#if __STDC_VERSION__ >= 201112L
  #define NELUA_NORETURN _Noreturn
#elif defined(__GNUC__)
  #define NELUA_NORETURN __attribute__((noreturn))
#elif defined(_MSC_VER)
  #define NELUA_NORETURN __declspec(noreturn)
#else
  #define NELUA_NORETURN
#endif
#include <stddef.h>
/* Macro used to force not inlining a function. */
#ifdef __GNUC__
  #define NELUA_NOINLINE __attribute__((noinline))
#elif defined(_MSC_VER)
  #define NELUA_NOINLINE __declspec(noinline)
#else
  #define NELUA_NOINLINE
#endif
/* Macro used for branch prediction. */
#if defined(__GNUC__) || defined(__clang__)
  #define NELUA_LIKELY(x) __builtin_expect(x, 1)
#else
  #define NELUA_LIKELY(x) (x)
#endif
#include <raylib.h>
/* Macro used suppress sanitizer errors when the GC is scanning. */
#if defined(__has_feature)
  #if __has_feature(address_sanitizer)
    #define NELUA_GC_NO_SANITIZE __attribute__((no_sanitize_address))
  #elif __has_feature(memory_sanitizer)
    #define NELUA_GC_NO_SANITIZE __attribute__((no_sanitize_memory))
  #endif
#endif
#ifndef NELUA_GC_NO_SANITIZE
  #if defined(__SANITIZE_ADDRESS__)
    #define NELUA_GC_NO_SANITIZE __attribute__((no_sanitize_address))
  #else
    #define NELUA_GC_NO_SANITIZE
  #endif
#endif
#include <setjmp.h>
/* Macro used sign that a type punning cast may alias (related to strict aliasing). */
#ifdef __GNUC__
  #define NELUA_MAYALIAS __attribute__((may_alias))
#else
  #define NELUA_MAYALIAS
#endif
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
/* ------------------------------ DECLARATIONS ------------------------------ */
typedef struct nlniltype {} nlniltype;
typedef struct nlniltype nltype;
static NELUA_INLINE void nelua_memory_copy(void* dest, void* src, uintptr_t n);
static NELUA_INLINE void nelua_write_stderr(const char* msg, uintptr_t len, bool flush);
static NELUA_NORETURN void nelua_abort(void);
typedef struct nlstring nlstring;
typedef uint8_t* nluint8_arr0_ptr;
struct nlstring {
  nluint8_arr0_ptr data;
  uintptr_t size;
};
NELUA_STATIC_ASSERT(sizeof(nlstring) == 16 && NELUA_ALIGNOF(nlstring) == 8, "Nelua and C disagree on type size or align");
static void nelua_assert_line_1(bool cond, nlstring msg);
static NELUA_INLINE void nelua_memory_zero(void* dest, uintptr_t n);
static void nelua_assert_line_2(bool cond, nlstring msg);
static NELUA_INLINE bool nelua_memory_equals(void* a, void* b, uintptr_t n);
static void nelua_assert_line_3(bool cond, nlstring msg);
typedef struct engine_event_event_Event engine_event_event_Event;
struct engine_event_event_Event {
  nlstring name;
  bool fired;
};
NELUA_STATIC_ASSERT(sizeof(engine_event_event_Event) == 24 && NELUA_ALIGNOF(engine_event_event_Event) == 8, "Nelua and C disagree on type size or align");
typedef struct nlmulret_nlboolean_nlint64_engine_event_event_Event {
  bool r1;
  int64_t r2;
  engine_event_event_Event r3;
} nlmulret_nlboolean_nlint64_engine_event_event_Event;
typedef struct nelua_vector_Event_ nelua_vector_Event_;
typedef nelua_vector_Event_* nelua_vector_Event__ptr;
typedef nlmulret_nlboolean_nlint64_engine_event_event_Event (*function_5gquHoPNaDqkV7fJH)(nelua_vector_Event__ptr, int64_t);
typedef struct nelua_span_Event_ nelua_span_Event_;
typedef engine_event_event_Event* engine_event_event_Event_arr0_ptr;
struct nelua_span_Event_ {
  engine_event_event_Event_arr0_ptr data;
  uintptr_t size;
};
NELUA_STATIC_ASSERT(sizeof(nelua_span_Event_) == 16 && NELUA_ALIGNOF(nelua_span_Event_) == 8, "Nelua and C disagree on type size or align");
typedef struct nelua_GCAllocator nelua_GCAllocator;
struct nelua_GCAllocator {};
struct nelua_vector_Event_ {
  nelua_span_Event_ data;
  uintptr_t size;
  nelua_GCAllocator allocator;
};
NELUA_STATIC_ASSERT(sizeof(nelua_vector_Event_) == 24 && NELUA_ALIGNOF(nelua_vector_Event_) == 8, "Nelua and C disagree on type size or align");
typedef struct nlmulret_function_5gquHoPNaDqkV7fJH_nelua_vector_Event__ptr_nlint64 {
  function_5gquHoPNaDqkV7fJH r1;
  nelua_vector_Event__ptr r2;
  int64_t r3;
} nlmulret_function_5gquHoPNaDqkV7fJH_nelua_vector_Event__ptr_nlint64;
static NELUA_INLINE nlmulret_function_5gquHoPNaDqkV7fJH_nelua_vector_Event__ptr_nlint64 nelua_ipairs_1(nelua_vector_Event__ptr a);
static NELUA_INLINE nlmulret_nlboolean_nlint64_engine_event_event_Event nelua_ipairs_next(nelua_vector_Event__ptr a_1, int64_t k);
static NELUA_NORETURN void nelua_panic_cstring(const char* s);
static NELUA_INLINE void* nelua_assert_deref(void* p);
static NELUA_INLINE uintptr_t nelua_assert_narrow_nlint64_nlusize(int64_t x);
typedef engine_event_event_Event* engine_event_event_Event_ptr;
typedef struct nlmulret_nlboolean_nlint64_engine_event_event_Event_ptr {
  bool r1;
  int64_t r2;
  engine_event_event_Event_ptr r3;
} nlmulret_nlboolean_nlint64_engine_event_event_Event_ptr;
typedef nlmulret_nlboolean_nlint64_engine_event_event_Event_ptr (*function_DMiQwk1wKUehs9jb)(nelua_vector_Event__ptr, int64_t);
typedef struct nlmulret_function_DMiQwk1wKUehs9jb_nelua_vector_Event__ptr_nlint64 {
  function_DMiQwk1wKUehs9jb r1;
  nelua_vector_Event__ptr r2;
  int64_t r3;
} nlmulret_function_DMiQwk1wKUehs9jb_nelua_vector_Event__ptr_nlint64;
static NELUA_INLINE nlmulret_function_DMiQwk1wKUehs9jb_nelua_vector_Event__ptr_nlint64 nelua_mipairs_1(nelua_vector_Event__ptr a);
static NELUA_INLINE nlmulret_nlboolean_nlint64_engine_event_event_Event_ptr nelua_mipairs_next(nelua_vector_Event__ptr a_2, int64_t k);
typedef struct engine_gui_gui_UIWindow engine_gui_gui_UIWindow;
typedef engine_gui_gui_UIWindow* engine_gui_gui_UIWindow_ptr;
typedef struct nlmulret_nlboolean_nlint64_engine_gui_gui_UIWindow_ptr {
  bool r1;
  int64_t r2;
  engine_gui_gui_UIWindow_ptr r3;
} nlmulret_nlboolean_nlint64_engine_gui_gui_UIWindow_ptr;
typedef struct nelua_vector_UIWindow_ nelua_vector_UIWindow_;
typedef nelua_vector_UIWindow_* nelua_vector_UIWindow__ptr;
typedef nlmulret_nlboolean_nlint64_engine_gui_gui_UIWindow_ptr (*function_Po1535aji1YbmWk6)(nelua_vector_UIWindow__ptr, int64_t);
typedef struct nelua_span_UIWindow_ nelua_span_UIWindow_;
typedef struct nelua_vector_Widget_ nelua_vector_Widget_;
typedef struct nelua_span_Widget_ nelua_span_Widget_;
typedef struct engine_gui_gui_Widget engine_gui_gui_Widget;
typedef engine_gui_gui_Widget* engine_gui_gui_Widget_arr0_ptr;
struct nelua_span_Widget_ {
  engine_gui_gui_Widget_arr0_ptr data;
  uintptr_t size;
};
NELUA_STATIC_ASSERT(sizeof(nelua_span_Widget_) == 16 && NELUA_ALIGNOF(nelua_span_Widget_) == 8, "Nelua and C disagree on type size or align");
struct nelua_vector_Widget_ {
  nelua_span_Widget_ data;
  uintptr_t size;
  nelua_GCAllocator allocator;
};
NELUA_STATIC_ASSERT(sizeof(nelua_vector_Widget_) == 24 && NELUA_ALIGNOF(nelua_vector_Widget_) == 8, "Nelua and C disagree on type size or align");
typedef struct nelua_vector_boolean_ nelua_vector_boolean_;
typedef struct nelua_span_boolean_ nelua_span_boolean_;
typedef bool* nlboolean_arr0_ptr;
struct nelua_span_boolean_ {
  nlboolean_arr0_ptr data;
  uintptr_t size;
};
NELUA_STATIC_ASSERT(sizeof(nelua_span_boolean_) == 16 && NELUA_ALIGNOF(nelua_span_boolean_) == 8, "Nelua and C disagree on type size or align");
struct nelua_vector_boolean_ {
  nelua_span_boolean_ data;
  uintptr_t size;
  nelua_GCAllocator allocator;
};
NELUA_STATIC_ASSERT(sizeof(nelua_vector_boolean_) == 24 && NELUA_ALIGNOF(nelua_vector_boolean_) == 8, "Nelua and C disagree on type size or align");
struct engine_gui_gui_UIWindow {
  nlstring menuBarText;
  nlstring windowName;
  Vector2 size;
  Vector2 pos;
  Color borderColor;
  Color bgColor;
  Color fgColor;
  int nextWidgetSpotAvailable;
  int menuTextPadding;
  int menuFontSize;
  int menuBarSize;
  int borderSize;
  bool menuBarEnabled;
  bool spaceOccupied;
  bool isShown;
  bool moving;
  nelua_vector_Widget_ Widgets;
  nelua_vector_boolean_ widgetSpotsAvailable;
  Vector2 originalPosition;
  Vector2 mouseOffset;
  int grabDebounce;
};
NELUA_STATIC_ASSERT(sizeof(engine_gui_gui_UIWindow) == 160 && NELUA_ALIGNOF(engine_gui_gui_UIWindow) == 8, "Nelua and C disagree on type size or align");
typedef engine_gui_gui_UIWindow* engine_gui_gui_UIWindow_arr0_ptr;
struct nelua_span_UIWindow_ {
  engine_gui_gui_UIWindow_arr0_ptr data;
  uintptr_t size;
};
NELUA_STATIC_ASSERT(sizeof(nelua_span_UIWindow_) == 16 && NELUA_ALIGNOF(nelua_span_UIWindow_) == 8, "Nelua and C disagree on type size or align");
struct nelua_vector_UIWindow_ {
  nelua_span_UIWindow_ data;
  uintptr_t size;
  nelua_GCAllocator allocator;
};
NELUA_STATIC_ASSERT(sizeof(nelua_vector_UIWindow_) == 24 && NELUA_ALIGNOF(nelua_vector_UIWindow_) == 8, "Nelua and C disagree on type size or align");
struct engine_gui_gui_Widget {
  nlstring widgetName;
  nlstring widgetType;
  nlstring widgetText;
  int fontSize;
  Vector2 position;
  Vector2 size;
  int borderSize;
  bool spaceOccupied;
  Color borderColor;
  Color bgColor;
  Color fgColor;
  Vector2 tl;
  Vector2 br;
  Vector2 tlW;
  Vector2 brW;
  Vector2 windowPosition;
  bool isHighlighted;
  bool alwaysDrawn;
  bool autoSize;
  bool isShown;
  bool isDown;
};
NELUA_STATIC_ASSERT(sizeof(engine_gui_gui_Widget) == 136 && NELUA_ALIGNOF(engine_gui_gui_Widget) == 8, "Nelua and C disagree on type size or align");
typedef struct nlmulret_function_Po1535aji1YbmWk6_nelua_vector_UIWindow__ptr_nlint64 {
  function_Po1535aji1YbmWk6 r1;
  nelua_vector_UIWindow__ptr r2;
  int64_t r3;
} nlmulret_function_Po1535aji1YbmWk6_nelua_vector_UIWindow__ptr_nlint64;
static NELUA_INLINE nlmulret_function_Po1535aji1YbmWk6_nelua_vector_UIWindow__ptr_nlint64 nelua_mipairs_2(nelua_vector_UIWindow__ptr a);
static NELUA_INLINE nlmulret_nlboolean_nlint64_engine_gui_gui_UIWindow_ptr nelua_mipairs_next_1(nelua_vector_UIWindow__ptr a_3, int64_t k);
typedef engine_gui_gui_Widget* engine_gui_gui_Widget_ptr;
typedef struct nlmulret_nlboolean_nlint64_engine_gui_gui_Widget_ptr {
  bool r1;
  int64_t r2;
  engine_gui_gui_Widget_ptr r3;
} nlmulret_nlboolean_nlint64_engine_gui_gui_Widget_ptr;
typedef nelua_vector_Widget_* nelua_vector_Widget__ptr;
typedef nlmulret_nlboolean_nlint64_engine_gui_gui_Widget_ptr (*function_3dp1Cn41EcGHHu18K)(nelua_vector_Widget__ptr, int64_t);
typedef struct nlmulret_function_3dp1Cn41EcGHHu18K_nelua_vector_Widget__ptr_nlint64 {
  function_3dp1Cn41EcGHHu18K r1;
  nelua_vector_Widget__ptr r2;
  int64_t r3;
} nlmulret_function_3dp1Cn41EcGHHu18K_nelua_vector_Widget__ptr_nlint64;
static NELUA_INLINE nlmulret_function_3dp1Cn41EcGHHu18K_nelua_vector_Widget__ptr_nlint64 nelua_mipairs_3(nelua_vector_Widget__ptr a);
static NELUA_INLINE nlmulret_nlboolean_nlint64_engine_gui_gui_Widget_ptr nelua_mipairs_next_2(nelua_vector_Widget__ptr a_4, int64_t k);
typedef struct nelua_GCItem nelua_GCItem;
typedef nelua_GCItem* nelua_GCItem_ptr;
typedef struct nlmulret_nlboolean_nlpointer_nelua_GCItem_ptr {
  bool r1;
  void* r2;
  nelua_GCItem_ptr r3;
} nlmulret_nlboolean_nlpointer_nelua_GCItem_ptr;
typedef struct nelua_hashmap_iteratorT nelua_hashmap_iteratorT;
typedef nelua_hashmap_iteratorT* nelua_hashmap_iteratorT_ptr;
typedef nlmulret_nlboolean_nlpointer_nelua_GCItem_ptr (*function_jDKmpuEzyNDncrbK)(nelua_hashmap_iteratorT_ptr, void*);
typedef struct nelua_hashmap_pointer__GCItem_ nelua_hashmap_pointer__GCItem_;
typedef nelua_hashmap_pointer__GCItem_* nelua_hashmap_pointer__GCItem__ptr;
struct nelua_hashmap_iteratorT {
  nelua_hashmap_pointer__GCItem__ptr container;
  uintptr_t index;
};
NELUA_STATIC_ASSERT(sizeof(nelua_hashmap_iteratorT) == 16 && NELUA_ALIGNOF(nelua_hashmap_iteratorT) == 8, "Nelua and C disagree on type size or align");
typedef struct nelua_span_usize_ nelua_span_usize_;
typedef uintptr_t* nlusize_arr0_ptr;
struct nelua_span_usize_ {
  nlusize_arr0_ptr data;
  uintptr_t size;
};
NELUA_STATIC_ASSERT(sizeof(nelua_span_usize_) == 16 && NELUA_ALIGNOF(nelua_span_usize_) == 8, "Nelua and C disagree on type size or align");
typedef struct nelua_span_hashmapnode_pointer__GCItem__ nelua_span_hashmapnode_pointer__GCItem__;
typedef struct nelua_hashmapnode_pointer__GCItem_ nelua_hashmapnode_pointer__GCItem_;
typedef nelua_hashmapnode_pointer__GCItem_* nelua_hashmapnode_pointer__GCItem__arr0_ptr;
struct nelua_span_hashmapnode_pointer__GCItem__ {
  nelua_hashmapnode_pointer__GCItem__arr0_ptr data;
  uintptr_t size;
};
NELUA_STATIC_ASSERT(sizeof(nelua_span_hashmapnode_pointer__GCItem__) == 16 && NELUA_ALIGNOF(nelua_span_hashmapnode_pointer__GCItem__) == 8, "Nelua and C disagree on type size or align");
typedef struct nelua_GeneralAllocator nelua_GeneralAllocator;
struct nelua_GeneralAllocator {};
struct nelua_hashmap_pointer__GCItem_ {
  nelua_span_usize_ buckets;
  nelua_span_hashmapnode_pointer__GCItem__ nodes;
  uintptr_t size;
  uintptr_t free_index;
  nelua_GeneralAllocator allocator;
};
NELUA_STATIC_ASSERT(sizeof(nelua_hashmap_pointer__GCItem_) == 48 && NELUA_ALIGNOF(nelua_hashmap_pointer__GCItem_) == 8, "Nelua and C disagree on type size or align");
typedef void (*nelua_GCFinalizerCallback)(void*, void*);
struct nelua_GCItem {
  uintptr_t flags;
  uintptr_t size;
  void* ptr;
  nelua_GCFinalizerCallback finalizer;
  void* userdata;
};
NELUA_STATIC_ASSERT(sizeof(nelua_GCItem) == 40 && NELUA_ALIGNOF(nelua_GCItem) == 8, "Nelua and C disagree on type size or align");
struct nelua_hashmapnode_pointer__GCItem_ {
  void* key;
  nelua_GCItem value;
  bool filled;
  uintptr_t next;
};
NELUA_STATIC_ASSERT(sizeof(nelua_hashmapnode_pointer__GCItem_) == 64 && NELUA_ALIGNOF(nelua_hashmapnode_pointer__GCItem_) == 8, "Nelua and C disagree on type size or align");
typedef struct nlmulret_function_jDKmpuEzyNDncrbK_nelua_hashmap_iteratorT_nlpointer {
  function_jDKmpuEzyNDncrbK r1;
  nelua_hashmap_iteratorT r2;
  void* r3;
} nlmulret_function_jDKmpuEzyNDncrbK_nelua_hashmap_iteratorT_nlpointer;
static NELUA_INLINE nlmulret_function_jDKmpuEzyNDncrbK_nelua_hashmap_iteratorT_nlpointer nelua_mpairs_1(nelua_hashmap_pointer__GCItem__ptr a);
typedef struct nelua_span_uint8_ nelua_span_uint8_;
struct nelua_span_uint8_ {
  nluint8_arr0_ptr data;
  uintptr_t size;
};
NELUA_STATIC_ASSERT(sizeof(nelua_span_uint8_) == 16 && NELUA_ALIGNOF(nelua_span_uint8_) == 8, "Nelua and C disagree on type size or align");
static NELUA_INLINE bool nelua_span_uint8__empty(nelua_span_uint8_ self);
typedef uint8_t* nluint8_ptr;
static NELUA_INLINE nluint8_ptr nelua_span_uint8____atindex(nelua_span_uint8_ self, uintptr_t i);
static void nelua_assert_line_4(bool cond, nlstring msg);
typedef void** nlpointer_ptr;
typedef struct nelua_span_pointer_ nelua_span_pointer_;
typedef void** nlpointer_arr0_ptr;
struct nelua_span_pointer_ {
  nlpointer_arr0_ptr data;
  uintptr_t size;
};
NELUA_STATIC_ASSERT(sizeof(nelua_span_pointer_) == 16 && NELUA_ALIGNOF(nelua_span_pointer_) == 8, "Nelua and C disagree on type size or align");
static NELUA_INLINE nlpointer_ptr nelua_span_pointer____atindex(nelua_span_pointer_ self, uintptr_t i);
static void nelua_assert_line_5(bool cond, nlstring msg);
typedef struct nelua_GCMarkRange nelua_GCMarkRange;
typedef nelua_GCMarkRange* nelua_GCMarkRange_ptr;
struct nelua_GCMarkRange {
  uintptr_t low;
  uintptr_t high;
};
NELUA_STATIC_ASSERT(sizeof(nelua_GCMarkRange) == 16 && NELUA_ALIGNOF(nelua_GCMarkRange) == 8, "Nelua and C disagree on type size or align");
typedef struct nelua_span_GCMarkRange_ nelua_span_GCMarkRange_;
typedef nelua_GCMarkRange* nelua_GCMarkRange_arr0_ptr;
struct nelua_span_GCMarkRange_ {
  nelua_GCMarkRange_arr0_ptr data;
  uintptr_t size;
};
NELUA_STATIC_ASSERT(sizeof(nelua_span_GCMarkRange_) == 16 && NELUA_ALIGNOF(nelua_span_GCMarkRange_) == 8, "Nelua and C disagree on type size or align");
static NELUA_INLINE nelua_GCMarkRange_ptr nelua_span_GCMarkRange____atindex(nelua_span_GCMarkRange_ self, uintptr_t i);
static void nelua_assert_line_6(bool cond, nlstring msg);
typedef uintptr_t* nlusize_ptr;
static NELUA_INLINE nlusize_ptr nelua_span_usize____atindex(nelua_span_usize_ self, uintptr_t i);
static void nelua_assert_line_7(bool cond, nlstring msg);
typedef nelua_hashmapnode_pointer__GCItem_* nelua_hashmapnode_pointer__GCItem__ptr;
static NELUA_INLINE nelua_hashmapnode_pointer__GCItem__ptr nelua_span_hashmapnode_pointer__GCItem_____atindex(nelua_span_hashmapnode_pointer__GCItem__ self, uintptr_t i);
static void nelua_assert_line_8(bool cond, nlstring msg);
static NELUA_INLINE engine_event_event_Event_ptr nelua_span_Event____atindex(nelua_span_Event_ self, uintptr_t i);
static void nelua_assert_line_9(bool cond, nlstring msg);
static NELUA_INLINE engine_gui_gui_Widget_ptr nelua_span_Widget____atindex(nelua_span_Widget_ self, uintptr_t i);
static void nelua_assert_line_10(bool cond, nlstring msg);
static NELUA_INLINE engine_gui_gui_UIWindow_ptr nelua_span_UIWindow____atindex(nelua_span_UIWindow_ self, uintptr_t i);
static void nelua_assert_line_11(bool cond, nlstring msg);
static NELUA_INLINE void nelua_memory_spanset_1(nelua_span_usize_ dest, uintptr_t x);
typedef struct nelua_vector_pointer_ nelua_vector_pointer_;
typedef nelua_vector_pointer_* nelua_vector_pointer__ptr;
struct nelua_vector_pointer_ {
  nelua_span_pointer_ data;
  uintptr_t size;
  nelua_GeneralAllocator allocator;
};
NELUA_STATIC_ASSERT(sizeof(nelua_vector_pointer_) == 24 && NELUA_ALIGNOF(nelua_vector_pointer_) == 8, "Nelua and C disagree on type size or align");
static void nelua_vector_pointer__clear(nelua_vector_pointer__ptr self);
static void nelua_vector_pointer__destroy(nelua_vector_pointer__ptr self);
static NELUA_NOINLINE void nelua_vectorT_grow(nelua_vector_pointer__ptr self);
static void nelua_assert_line_12(bool cond, nlstring msg);
static void nelua_vector_pointer__push(nelua_vector_pointer__ptr self, void* v);
static NELUA_INLINE nlpointer_ptr nelua_vector_pointer____atindex(nelua_vector_pointer__ptr self, uintptr_t pos);
static void nelua_assert_line_13(bool cond, nlstring msg);
typedef struct nelua_vector_GCMarkRange_ nelua_vector_GCMarkRange_;
typedef nelua_vector_GCMarkRange_* nelua_vector_GCMarkRange__ptr;
struct nelua_vector_GCMarkRange_ {
  nelua_span_GCMarkRange_ data;
  uintptr_t size;
  nelua_GeneralAllocator allocator;
};
NELUA_STATIC_ASSERT(sizeof(nelua_vector_GCMarkRange_) == 24 && NELUA_ALIGNOF(nelua_vector_GCMarkRange_) == 8, "Nelua and C disagree on type size or align");
static void nelua_vector_GCMarkRange__destroy(nelua_vector_GCMarkRange__ptr self);
static NELUA_NOINLINE void nelua_vectorT_grow_1(nelua_vector_GCMarkRange__ptr self);
static void nelua_assert_line_14(bool cond, nlstring msg);
static void nelua_vector_GCMarkRange__push(nelua_vector_GCMarkRange__ptr self, nelua_GCMarkRange v);
static nelua_GCMarkRange nelua_vector_GCMarkRange__pop(nelua_vector_GCMarkRange__ptr self);
static void nelua_assert_line_15(bool cond, nlstring msg);
static NELUA_NOINLINE void nelua_vectorT_grow_2(nelua_vector_Event__ptr self);
static void nelua_assert_line_16(bool cond, nlstring msg);
static void nelua_vector_Event__push(nelua_vector_Event__ptr self, engine_event_event_Event v);
static NELUA_INLINE engine_event_event_Event_ptr nelua_vector_Event____atindex(nelua_vector_Event__ptr self, uintptr_t pos);
static void nelua_assert_line_17(bool cond, nlstring msg);
static NELUA_INLINE intptr_t nelua_vector_Event____len(nelua_vector_Event__ptr self);
static NELUA_NOINLINE void nelua_vectorT_grow_3(nelua_vector_Widget__ptr self);
static void nelua_assert_line_18(bool cond, nlstring msg);
static void nelua_vector_Widget__push(nelua_vector_Widget__ptr self, engine_gui_gui_Widget v);
static NELUA_INLINE engine_gui_gui_Widget_ptr nelua_vector_Widget____atindex(nelua_vector_Widget__ptr self, uintptr_t pos);
static void nelua_assert_line_19(bool cond, nlstring msg);
static NELUA_INLINE intptr_t nelua_vector_Widget____len(nelua_vector_Widget__ptr self);
static NELUA_NOINLINE void nelua_vectorT_grow_5(nelua_vector_UIWindow__ptr self);
static void nelua_assert_line_20(bool cond, nlstring msg);
static void nelua_vector_UIWindow__push(nelua_vector_UIWindow__ptr self, engine_gui_gui_UIWindow v);
static NELUA_INLINE engine_gui_gui_UIWindow_ptr nelua_vector_UIWindow____atindex(nelua_vector_UIWindow__ptr self, uintptr_t pos);
static void nelua_assert_line_21(bool cond, nlstring msg);
static NELUA_INLINE intptr_t nelua_vector_UIWindow____len(nelua_vector_UIWindow__ptr self);
static nelua_GeneralAllocator nelua_general_allocator;
typedef nelua_GeneralAllocator* nelua_GeneralAllocator_ptr;
static NELUA_INLINE void* nelua_GeneralAllocator_alloc_1(nelua_GeneralAllocator_ptr self, uintptr_t size, uintptr_t flags);
static NELUA_INLINE void* nelua_GeneralAllocator_alloc_2(nelua_GeneralAllocator_ptr self, uintptr_t size, nlniltype flags);
static NELUA_INLINE void* nelua_GeneralAllocator_alloc0_1(nelua_GeneralAllocator_ptr self, uintptr_t size, nlniltype flags);
static NELUA_INLINE void* nelua_GeneralAllocator_alloc0_2(nelua_GeneralAllocator_ptr self, uintptr_t size, uintptr_t flags);
static NELUA_INLINE void nelua_GeneralAllocator_dealloc(nelua_GeneralAllocator_ptr self, void* p);
static NELUA_INLINE void* nelua_GeneralAllocator_realloc(nelua_GeneralAllocator_ptr self, void* p, uintptr_t newsize, uintptr_t oldsize);
static void* nelua_GeneralAllocator_realloc0(nelua_GeneralAllocator_ptr self, void* p, uintptr_t newsize, uintptr_t oldsize);
static nelua_span_pointer_ nelua_GeneralAllocator_spanalloc_1(nelua_GeneralAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags);
static nelua_span_GCMarkRange_ nelua_GeneralAllocator_spanalloc_2(nelua_GeneralAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags);
static nelua_span_usize_ nelua_GeneralAllocator_spanalloc_3(nelua_GeneralAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags);
static nelua_span_hashmapnode_pointer__GCItem__ nelua_GeneralAllocator_spanalloc0_1(nelua_GeneralAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags);
static void nelua_GeneralAllocator_spandealloc_1(nelua_GeneralAllocator_ptr self, nelua_span_pointer_ s);
static void nelua_GeneralAllocator_spandealloc_2(nelua_GeneralAllocator_ptr self, nelua_span_GCMarkRange_ s);
static void nelua_GeneralAllocator_spandealloc_3(nelua_GeneralAllocator_ptr self, nelua_span_usize_ s);
static void nelua_GeneralAllocator_spandealloc_4(nelua_GeneralAllocator_ptr self, nelua_span_hashmapnode_pointer__GCItem__ s);
static nelua_span_pointer_ nelua_GeneralAllocator_spanrealloc_1(nelua_GeneralAllocator_ptr self, nelua_span_pointer_ s, uintptr_t size);
static nelua_span_GCMarkRange_ nelua_GeneralAllocator_spanrealloc_2(nelua_GeneralAllocator_ptr self, nelua_span_GCMarkRange_ s, uintptr_t size);
static nelua_span_usize_ nelua_GeneralAllocator_spanrealloc_3(nelua_GeneralAllocator_ptr self, nelua_span_usize_ s, uintptr_t size);
static nelua_span_pointer_ nelua_GeneralAllocator_xspanrealloc_1(nelua_GeneralAllocator_ptr self, nelua_span_pointer_ s, uintptr_t size);
static NELUA_NORETURN void nelua_panic_string(nlstring s);
static nelua_span_GCMarkRange_ nelua_GeneralAllocator_xspanrealloc_2(nelua_GeneralAllocator_ptr self, nelua_span_GCMarkRange_ s, uintptr_t size);
static nelua_span_usize_ nelua_GeneralAllocator_xspanrealloc_3(nelua_GeneralAllocator_ptr self, nelua_span_usize_ s, uintptr_t size);
static nelua_span_hashmapnode_pointer__GCItem__ nelua_GeneralAllocator_spanrealloc0_1(nelua_GeneralAllocator_ptr self, nelua_span_hashmapnode_pointer__GCItem__ s, uintptr_t size);
static nelua_span_hashmapnode_pointer__GCItem__ nelua_GeneralAllocator_xspanrealloc0_1(nelua_GeneralAllocator_ptr self, nelua_span_hashmapnode_pointer__GCItem__ s, uintptr_t size);
static uintptr_t nelua_hash_hash_1(void* v);
static NELUA_INLINE uintptr_t nelua_ceilidiv(uintptr_t x, uintptr_t y);
static NELUA_INLINE uintptr_t nelua_hashmod(uintptr_t h, uintptr_t n);
static NELUA_INLINE uintptr_t nelua_roundpow2(uintptr_t n);
static void nelua_hashmap_pointer__GCItem__destroy(nelua_hashmap_pointer__GCItem__ptr self);
typedef struct nlmulret_nlusize_nlusize_nlusize {
  uintptr_t r1;
  uintptr_t r2;
  uintptr_t r3;
} nlmulret_nlusize_nlusize_nlusize;
static NELUA_INLINE nlmulret_nlusize_nlusize_nlusize nelua_hashmap_pointer__GCItem___find(nelua_hashmap_pointer__GCItem__ptr self, void* key);
static NELUA_NOINLINE void nelua_hashmap_pointer__GCItem__rehash(nelua_hashmap_pointer__GCItem__ptr self, uintptr_t bucket_count);
static void nelua_assert_line_22(bool cond);
static uintptr_t nelua_hashmap_pointer__GCItem___at(nelua_hashmap_pointer__GCItem__ptr self, void* key);
static void nelua_assert_line_23(bool cond, nlstring msg);
static nelua_GCItem_ptr nelua_hashmap_pointer__GCItem____atindex(nelua_hashmap_pointer__GCItem__ptr self, void* key);
static nelua_GCItem_ptr nelua_hashmap_pointer__GCItem__peek(nelua_hashmap_pointer__GCItem__ptr self, void* key);
static nelua_GCItem nelua_hashmap_pointer__GCItem__remove(nelua_hashmap_pointer__GCItem__ptr self, void* key);
static uintptr_t nelua_hashmap_pointer__GCItem__bucketcount(nelua_hashmap_pointer__GCItem__ptr self);
static NELUA_INLINE nelua_hashmapnode_pointer__GCItem__ptr nelua_hashmap_iteratorT__next_node(nelua_hashmap_iteratorT_ptr self, void* key);
static NELUA_INLINE nlmulret_nlboolean_nlpointer_nelua_GCItem_ptr nelua_hashmap_iteratorT_mnext(nelua_hashmap_iteratorT_ptr self, void* key);
static NELUA_INLINE nlmulret_function_jDKmpuEzyNDncrbK_nelua_hashmap_iteratorT_nlpointer nelua_hashmap_pointer__GCItem____mpairs(nelua_hashmap_pointer__GCItem__ptr self);
static NELUA_INLINE bool nelua_hasflag(uintptr_t flags, uintptr_t flag);
static NELUA_INLINE uintptr_t nelua_align_forward(uintptr_t addr, uintptr_t align);
static NELUA_INLINE bool nelua_GCItem_ismarked(nelua_GCItem_ptr self);
typedef struct nelua_GC nelua_GC;
struct nelua_GC {
  bool running;
  bool collecting;
  uintptr_t pause;
  uintptr_t membytes;
  uintptr_t lastmembytes;
  uintptr_t minaddr;
  uintptr_t maxaddr;
  uintptr_t stacktop;
  uintptr_t stackbottom;
  nelua_vector_pointer_ frees;
  nelua_vector_GCMarkRange_ markranges;
  nelua_hashmap_pointer__GCItem_ items;
};
NELUA_STATIC_ASSERT(sizeof(nelua_GC) == 160 && NELUA_ALIGNOF(nelua_GC) == 8, "Nelua and C disagree on type size or align");
static nelua_GC nelua_gc;
typedef nelua_GC* nelua_GC_ptr;
static void nelua_GC_unregister_1(nelua_GC_ptr self, void* ptr, bool finalize);
static void nelua_assert_line_24(bool cond, nlstring msg);
static NELUA_NOINLINE NELUA_GC_NO_SANITIZE void nelua_GC_markptrs(nelua_GC_ptr self, uintptr_t low, uintptr_t high);
static NELUA_NOINLINE void nelua_GC_markptr(nelua_GC_ptr self, void* ptr);
static NELUA_NOINLINE void nelua_GC_unmarkall(nelua_GC_ptr self);
static NELUA_NOINLINE void nelua_GC_markroot(nelua_GC_ptr self);
static NELUA_NOINLINE void nelua_GC_markstack(nelua_GC_ptr self);
typedef union nelua_RegsBuf nelua_RegsBuf;
union nelua_RegsBuf {
  jmp_buf regs;
  void* firstreg;
};
static void nelua_GC_mark(nelua_GC_ptr self);
typedef void (*function_5F616zmeWxFHshuob)(nelua_GC_ptr);
static NELUA_NOINLINE void nelua_GC_sweep(nelua_GC_ptr self);
static void nelua_assert_line_25(bool cond, nlstring msg);
static void nelua_assert_line_26(bool cond, nlstring msg);
static NELUA_NOINLINE void nelua_GC_collect(nelua_GC_ptr self);
static void nelua_GC_registerroots(nelua_GC_ptr self);
typedef void (*function_4cJAvFfHJEMFkKdi7)(void*, void*);
static bool nelua_GC_step(nelua_GC_ptr self);
static void nelua_GC_register(nelua_GC_ptr self, void* ptr, uintptr_t size, uintptr_t flags, function_4cJAvFfHJEMFkKdi7 finalizer, void* userdata);
static void nelua_assert_line_27(bool cond, nlstring msg);
static void nelua_GC_reregister(nelua_GC_ptr self, void* oldptr, void* newptr, uintptr_t newsize);
static void nelua_assert_line_28(bool cond, nlstring msg);
static void nelua_assert_line_29(bool cond, nlstring msg);
static void nelua_assert_line_30(bool cond, nlstring msg);
static void nelua_GC_restart(nelua_GC_ptr self);
static NELUA_NOINLINE void nelua_GC_init(nelua_GC_ptr self, void* stack);
static NELUA_NOINLINE void nelua_GC_destroy(nelua_GC_ptr self);
typedef char** nlcstring_ptr;
int main(int argc, nlcstring_ptr argv);
typedef int (*function_3vE21UhnrxvrKKPii)(int, nlcstring_ptr);
static nelua_GCAllocator nelua_gc_allocator;
typedef nelua_GCAllocator* nelua_GCAllocator_ptr;
static NELUA_NOINLINE void* nelua_GCAllocator_alloc_1(nelua_GCAllocator_ptr self, uintptr_t size, nlniltype flags, nlniltype finalizer, nlniltype userdata);
static NELUA_NOINLINE void* nelua_GCAllocator_alloc_2(nelua_GCAllocator_ptr self, uintptr_t size, nlniltype flags, nelua_GCFinalizerCallback finalizer, void* userdata);
static NELUA_NOINLINE void* nelua_GCAllocator_alloc_3(nelua_GCAllocator_ptr self, uintptr_t size, uintptr_t flags, nelua_GCFinalizerCallback finalizer, void* userdata);
static NELUA_NOINLINE void* nelua_GCAllocator_alloc0_2(nelua_GCAllocator_ptr self, uintptr_t size, uintptr_t flags, nelua_GCFinalizerCallback finalizer, void* userdata);
static NELUA_NOINLINE void nelua_GCAllocator_dealloc(nelua_GCAllocator_ptr self, void* ptr);
static NELUA_NOINLINE void* nelua_GCAllocator_realloc(nelua_GCAllocator_ptr self, void* ptr, uintptr_t newsize, uintptr_t oldsize);
static nelua_span_uint8_ nelua_GCAllocator_spanalloc_2(nelua_GCAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags, nlniltype finalizer, nlniltype userdata);
static nelua_span_Event_ nelua_GCAllocator_spanalloc_3(nelua_GCAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags, nlniltype finalizer, nlniltype userdata);
static nelua_span_Widget_ nelua_GCAllocator_spanalloc_4(nelua_GCAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags, nlniltype finalizer, nlniltype userdata);
static nelua_span_UIWindow_ nelua_GCAllocator_spanalloc_6(nelua_GCAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags, nlniltype finalizer, nlniltype userdata);
static nelua_span_uint8_ nelua_GCAllocator_spanalloc0_1(nelua_GCAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags, nlniltype finalizer, nlniltype userdata);
static void* nelua_GCAllocator_xalloc_1(nelua_GCAllocator_ptr self, uintptr_t size, nlniltype flags);
static void* nelua_GCAllocator_realloc0(nelua_GCAllocator_ptr self, void* p, uintptr_t newsize, uintptr_t oldsize);
static void nelua_GCAllocator_spandealloc_1(nelua_GCAllocator_ptr self, nelua_span_uint8_ s);
static nelua_span_uint8_ nelua_GCAllocator_spanrealloc_1(nelua_GCAllocator_ptr self, nelua_span_uint8_ s, uintptr_t size);
static nelua_span_Event_ nelua_GCAllocator_spanrealloc_3(nelua_GCAllocator_ptr self, nelua_span_Event_ s, uintptr_t size);
static nelua_span_Widget_ nelua_GCAllocator_spanrealloc_4(nelua_GCAllocator_ptr self, nelua_span_Widget_ s, uintptr_t size);
static nelua_span_UIWindow_ nelua_GCAllocator_spanrealloc_6(nelua_GCAllocator_ptr self, nelua_span_UIWindow_ s, uintptr_t size);
static nelua_span_uint8_ nelua_GCAllocator_xspanrealloc_1(nelua_GCAllocator_ptr self, nelua_span_uint8_ s, uintptr_t size);
static nelua_span_Event_ nelua_GCAllocator_xspanrealloc_3(nelua_GCAllocator_ptr self, nelua_span_Event_ s, uintptr_t size);
static nelua_span_Widget_ nelua_GCAllocator_xspanrealloc_4(nelua_GCAllocator_ptr self, nelua_span_Widget_ s, uintptr_t size);
static nelua_span_UIWindow_ nelua_GCAllocator_xspanrealloc_6(nelua_GCAllocator_ptr self, nelua_span_UIWindow_ s, uintptr_t size);
static nelua_span_uint8_ nelua_GCAllocator_spanrealloc0_1(nelua_GCAllocator_ptr self, nelua_span_uint8_ s, uintptr_t size);
typedef struct NELUA_MAYALIAS nluint8_arr48 {uint8_t v[48];} nluint8_arr48;
typedef union NELUA_MAYALIAS nluint8_arr48_cast {nluint8_arr48 a; uint8_t p[48];} nluint8_arr48_cast;
NELUA_STATIC_ASSERT(sizeof(nluint8_arr48) == 48 && NELUA_ALIGNOF(nluint8_arr48) == 1, "Nelua and C disagree on type size or align");
typedef nluint8_arr48* nluint8_arr48_ptr;
static nlstring nelua_strconv_1_int2str_1(nluint8_arr48_ptr buf, intptr_t x, nlniltype base);
static NELUA_INLINE uintptr_t nelua_assert_bounds_nlusize(uintptr_t index, uintptr_t len);
typedef struct nelua_stringbuilderT nelua_stringbuilderT;
typedef nelua_stringbuilderT* nelua_stringbuilderT_ptr;
struct nelua_stringbuilderT {
  nelua_span_uint8_ data;
  uintptr_t size;
  nelua_GCAllocator allocator;
};
NELUA_STATIC_ASSERT(sizeof(nelua_stringbuilderT) == 24 && NELUA_ALIGNOF(nelua_stringbuilderT) == 8, "Nelua and C disagree on type size or align");
static void nelua_stringbuilderT_destroy(nelua_stringbuilderT_ptr self);
static bool nelua_stringbuilderT_grow(nelua_stringbuilderT_ptr self, uintptr_t newsize);
static nelua_span_uint8_ nelua_stringbuilderT_prepare(nelua_stringbuilderT_ptr self, uintptr_t n);
static void nelua_stringbuilderT_commit(nelua_stringbuilderT_ptr self, uintptr_t n);
static void nelua_assert_line_31(bool cond, nlstring msg);
static nlstring nelua_stringbuilderT_promote(nelua_stringbuilderT_ptr self);
static nlstring nelua_nlstring_create(uintptr_t size);
static void nelua_assert_line_32(bool cond, nlstring msg);
static nlstring nelua_nlstring_copy(nlstring s);
static nlstring nelua_nlstring___concat_1(nlstring a, nlstring b);
static bool nelua_nlstring___eq(nlstring a, nlstring b);
static nlstring nelua_tostring_1(int x);
typedef struct nlmulret_nlstring_nlstring_nlint64 {
  nlstring r1;
  nlstring r2;
  int64_t r3;
} nlmulret_nlstring_nlstring_nlint64;
static nlmulret_nlstring_nlstring_nlint64 engine_fileystem_filesystem_fs_readfile(nlstring path);
static NELUA_INLINE char* nelua_assert_string2cstring(nlstring s);
static NELUA_INLINE nlstring nelua_cstring2string(const char* s);
typedef struct engine_information_handler_information_handler_InformationHandlerClass engine_information_handler_information_handler_InformationHandlerClass;
typedef engine_information_handler_information_handler_InformationHandlerClass* engine_information_handler_information_handler_InformationHandlerClass_ptr;
struct engine_information_handler_information_handler_InformationHandlerClass {
  int errorIndex;
  bool isHaulted;
};
NELUA_STATIC_ASSERT(sizeof(engine_information_handler_information_handler_InformationHandlerClass) == 8 && NELUA_ALIGNOF(engine_information_handler_information_handler_InformationHandlerClass) == 4, "Nelua and C disagree on type size or align");
static void engine_information_handler_information_handler_InformationHandlerClass_RaiseError(engine_information_handler_information_handler_InformationHandlerClass_ptr self, int severity, nlstring reason);
static void nelua_print_1(nlstring a1, nlstring a2, nlstring a3);
static char nelua_strlit_1[97] = "The program needed to hault, things could have gone wrong otherwhise. The reason is as follows: ";
static void nelua_print_2(nlstring a1, nlstring a2);
static void nelua_print_3(nlstring a1);
static void engine_information_handler_information_handler_InformationHandlerClass_Log(engine_information_handler_information_handler_InformationHandlerClass_ptr self, nlstring reason);
static void engine_information_handler_information_handler_InformationHandlerClass_Warn(engine_information_handler_information_handler_InformationHandlerClass_ptr self, nlstring reason);
static engine_information_handler_information_handler_InformationHandlerClass engine_information_handler_information_handler_InformationHandler;
typedef struct engine_utilities__UtilityClass engine_utilities__UtilityClass;
typedef engine_utilities__UtilityClass* engine_utilities__UtilityClass_ptr;
struct engine_utilities__UtilityClass {};
static bool engine_utilities__UtilityClass_IsInsideQuad(engine_utilities__UtilityClass_ptr self, Vector2 point, Vector2 tl, Vector2 br);
static void engine_utilities__UtilityClass_DrawBoxWithOutline(engine_utilities__UtilityClass_ptr self, Vector2 pos, Vector2 size, int pad, Color bgColor, Color borderColor);
static NELUA_INLINE int nelua_assert_narrow_nlfloat32_nlcint(float x);
static engine_utilities__UtilityClass engine_utilities__Utility;
typedef struct engine_mouse_mouse_MouseClass engine_mouse_mouse_MouseClass;
typedef engine_mouse_mouse_MouseClass* engine_mouse_mouse_MouseClass_ptr;
struct engine_mouse_mouse_MouseClass {
  int x;
  int y;
  bool LMBDown;
  bool MMBDown;
  bool RMBDown;
  bool LMBPressed;
  bool MMBPressed;
  bool RMBPressed;
  bool LMBReleased;
  int scrollWheelMove;
  bool insideUIElement;
  bool isGrabbing;
  nlstring windowGrabbed;
};
NELUA_STATIC_ASSERT(sizeof(engine_mouse_mouse_MouseClass) == 40 && NELUA_ALIGNOF(engine_mouse_mouse_MouseClass) == 8, "Nelua and C disagree on type size or align");
static void engine_mouse_mouse_MouseClass_Update(engine_mouse_mouse_MouseClass_ptr self);
static engine_mouse_mouse_MouseClass engine_mouse_mouse_Mouse;
typedef struct engine_event_manager_event_manager_EventManagerRecord engine_event_manager_event_manager_EventManagerRecord;
typedef engine_event_manager_event_manager_EventManagerRecord* engine_event_manager_event_manager_EventManagerRecord_ptr;
struct engine_event_manager_event_manager_EventManagerRecord {
  nelua_vector_Event_ Events;
};
NELUA_STATIC_ASSERT(sizeof(engine_event_manager_event_manager_EventManagerRecord) == 24 && NELUA_ALIGNOF(engine_event_manager_event_manager_EventManagerRecord) == 8, "Nelua and C disagree on type size or align");
static void engine_event_manager_event_manager_EventManagerRecord_RevealEvents(engine_event_manager_event_manager_EventManagerRecord_ptr self);
static NELUA_INLINE int64_t nelua_assert_narrow_nlusize_nlint64(uintptr_t x);
static void engine_event_manager_event_manager_EventManagerRecord_AddEvent(engine_event_manager_event_manager_EventManagerRecord_ptr self, nlstring uEventName);
static void engine_event_manager_event_manager_EventManagerRecord_FireEvent(engine_event_manager_event_manager_EventManagerRecord_ptr self, nlstring uEventName);
static void engine_event_manager_event_manager_EventManagerRecord_Cleanup(engine_event_manager_event_manager_EventManagerRecord_ptr self, nlstring uEventName);
static engine_event_event_Event engine_event_manager_event_manager_EventManagerRecord_GetEvent(engine_event_manager_event_manager_EventManagerRecord_ptr self, nlstring uEventName);
static engine_event_manager_event_manager_EventManagerRecord engine_event_manager_event_manager_EventManager;
static void engine_gui_gui_Widget_Init(engine_gui_gui_Widget_ptr self);
static void engine_gui_gui_Widget_UpdateVW(engine_gui_gui_Widget_ptr self);
static void engine_gui_gui_Widget_Draw(engine_gui_gui_Widget_ptr self);
static void engine_gui_gui_Widget_Update(engine_gui_gui_Widget_ptr self);
static void engine_gui_gui_UIWindow_Init(engine_gui_gui_UIWindow_ptr self);
static void engine_gui_gui_UIWindow_Update(engine_gui_gui_UIWindow_ptr self);
static void engine_gui_gui_UIWindow_Draw(engine_gui_gui_UIWindow_ptr self);
typedef struct engine_uimanager_uimanager_UIManagerClass engine_uimanager_uimanager_UIManagerClass;
typedef engine_uimanager_uimanager_UIManagerClass* engine_uimanager_uimanager_UIManagerClass_ptr;
struct engine_uimanager_uimanager_UIManagerClass {
  nelua_vector_UIWindow_ Windows;
  bool insideElement;
};
NELUA_STATIC_ASSERT(sizeof(engine_uimanager_uimanager_UIManagerClass) == 32 && NELUA_ALIGNOF(engine_uimanager_uimanager_UIManagerClass) == 8, "Nelua and C disagree on type size or align");
static void engine_uimanager_uimanager_UIManagerClass_AddWidget(engine_uimanager_uimanager_UIManagerClass_ptr self, nlstring uWindowName, nlstring uWidgetName, nlstring uWidgetType, nlstring uWidgetText, int uWidgetFontSize, Vector2 uWidgetPosition, Vector2 uWidgetSize, bool uWidgetAlwaysDrawn, bool uAutoSize);
static NELUA_INLINE uintptr_t nelua_assert_narrow_nlisize_nlusize(intptr_t x);
static void engine_uimanager_uimanager_UIManagerClass_ToggleWindow(engine_uimanager_uimanager_UIManagerClass_ptr self, nlstring uWindowName);
static void engine_uimanager_uimanager_UIManagerClass_ResetWindowPosition(engine_uimanager_uimanager_UIManagerClass_ptr self, nlstring uWindowName);
static void engine_uimanager_uimanager_UIManagerClass_Update(engine_uimanager_uimanager_UIManagerClass_ptr self);
static void engine_uimanager_uimanager_UIManagerClass_AddWindow(engine_uimanager_uimanager_UIManagerClass_ptr self, nlstring uMenuBarText, nlstring uWindowName, Vector2 uSize, Vector2 uPosition, Color uBorderColor, Color uFGColor, Color uBGColor, int uMenuTextPadding, int uMenuFontSize, int uMenuBarSize, int uBorderSize, bool uMenuBarEnabled);
static engine_uimanager_uimanager_UIManagerClass engine_uimanager_uimanager_UIManager;
static uint16_t main_screenWidth;
static NELUA_INLINE uint16_t nelua_assert_narrow_nlcint_nluint16(int x);
static uint16_t main_screenHeight;
typedef struct engine_render_render_RendererClass engine_render_render_RendererClass;
typedef engine_render_render_RendererClass* engine_render_render_RendererClass_ptr;
struct engine_render_render_RendererClass {
  bool isRenderingIntro;
  bool isRenderingFrames;
  int frameCount;
  int realFrameCount;
};
NELUA_STATIC_ASSERT(sizeof(engine_render_render_RendererClass) == 12 && NELUA_ALIGNOF(engine_render_render_RendererClass) == 4, "Nelua and C disagree on type size or align");
static void engine_render_render_RendererClass_BeginRenderIntro(engine_render_render_RendererClass_ptr self);
static NELUA_INLINE int nelua_assert_imod_nlcint(int a, int b);
static void engine_render_render_RendererClass_SetupEngineUI(engine_render_render_RendererClass_ptr self);
static void engine_render_render_RendererClass_Render(engine_render_render_RendererClass_ptr self);
static void engine_render_render_RendererClass_Init(engine_render_render_RendererClass_ptr self);
static engine_render_render_RendererClass engine_render_render_Renderer;
static void nelua_require_engine_render_render(nlniltype modname);
static uint16_t main_screenWidth_1;
static uint16_t main_screenHeight_1;
static int nelua_main(int argc, char** argv);
/* ------------------------------ DEFINITIONS ------------------------------- */
void nelua_write_stderr(const char* msg, uintptr_t len, bool flush) {
  if(len > 0 && msg) {
    fwrite(msg, 1, len, stderr);
  }
  if(flush) {
    fwrite("\n", 1, 1, stderr);
    fflush(stderr);
  }
}
void nelua_abort(void) {
  NELUA_UBSAN_UNREACHABLE();
  abort();
}
void nelua_assert_line_1(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/memory.nelua:27:14: runtime error: ", 54, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n  check(dest and src, 'invalid pointer')\n             ^~~~~~~\n", 63, true);
    nelua_abort();
  }
}
void nelua_memory_copy(void* dest, void* src, uintptr_t n) {
  if(NELUA_UNLIKELY((n == 0))) {
    return;
  }
  nelua_assert_line_1(((dest != NULL) && (src != NULL)), ((nlstring){(uint8_t*)"invalid pointer", 15}));
  memcpy(dest, src, (size_t)n);
}
void nelua_assert_line_2(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/memory.nelua:60:9: runtime error: ", 53, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n  check(dest, 'invalid pointer')\n        ^~~~\n", 47, true);
    nelua_abort();
  }
}
void nelua_memory_zero(void* dest, uintptr_t n) {
  if(NELUA_UNLIKELY((n == 0))) {
    return;
  }
  nelua_assert_line_2((dest != NULL), ((nlstring){(uint8_t*)"invalid pointer", 15}));
  memset(dest, 0, (size_t)n);
}
void nelua_assert_line_3(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/memory.nelua:89:11: runtime error: ", 54, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n  check(a and b, 'invalid pointer')\n          ^~~~~\n", 53, true);
    nelua_abort();
  }
}
bool nelua_memory_equals(void* a, void* b, uintptr_t n) {
  if(NELUA_UNLIKELY((n == 0))) {
    return true;
  }
  nelua_assert_line_3(((a != NULL) && (b != NULL)), ((nlstring){(uint8_t*)"invalid pointer", 15}));
  return (memcmp(a, b, (size_t)n) == 0);
}
void nelua_panic_cstring(const char* s) {
  if(s) {
    nelua_write_stderr(s, strlen(s), true);
  }
  nelua_abort();
}
void* nelua_assert_deref(void* p) {
  if(NELUA_UNLIKELY(p == NULL)) {
    nelua_panic_cstring("attempt to dereference a null pointer");
  }
  return p;
}
uintptr_t nelua_assert_narrow_nlint64_nlusize(int64_t x) {
  if(NELUA_UNLIKELY(x < 0)) {
    nelua_panic_cstring("narrow casting from int64 to usize failed");
  }
  return (uintptr_t)x;
}
nlmulret_nlboolean_nlint64_engine_event_event_Event nelua_ipairs_next(nelua_vector_Event__ptr a_1, int64_t k) {
  k = (k + 1);
  if((k >= (nelua_vector_Event____len(a_1) + 0))) {
    return (nlmulret_nlboolean_nlint64_engine_event_event_Event){false, 0, (engine_event_event_Event){0}};
  }
  return (nlmulret_nlboolean_nlint64_engine_event_event_Event){true, k, (*(engine_event_event_Event*)nelua_assert_deref(nelua_vector_Event____atindex(a_1, nelua_assert_narrow_nlint64_nlusize(k))))};
}
nlmulret_function_5gquHoPNaDqkV7fJH_nelua_vector_Event__ptr_nlint64 nelua_ipairs_1(nelua_vector_Event__ptr a) {
  return (nlmulret_function_5gquHoPNaDqkV7fJH_nelua_vector_Event__ptr_nlint64){nelua_ipairs_next, a, -1};
}
nlmulret_nlboolean_nlint64_engine_event_event_Event_ptr nelua_mipairs_next(nelua_vector_Event__ptr a_2, int64_t k) {
  k = (k + 1);
  if((k >= (nelua_vector_Event____len(a_2) + 0))) {
    return (nlmulret_nlboolean_nlint64_engine_event_event_Event_ptr){false, 0, ((engine_event_event_Event_ptr)NULL)};
  }
  return (nlmulret_nlboolean_nlint64_engine_event_event_Event_ptr){true, k, (&(*(engine_event_event_Event*)nelua_assert_deref(nelua_vector_Event____atindex(a_2, nelua_assert_narrow_nlint64_nlusize(k)))))};
}
nlmulret_function_DMiQwk1wKUehs9jb_nelua_vector_Event__ptr_nlint64 nelua_mipairs_1(nelua_vector_Event__ptr a) {
  return (nlmulret_function_DMiQwk1wKUehs9jb_nelua_vector_Event__ptr_nlint64){nelua_mipairs_next, a, -1};
}
nlmulret_nlboolean_nlint64_engine_gui_gui_UIWindow_ptr nelua_mipairs_next_1(nelua_vector_UIWindow__ptr a_3, int64_t k) {
  k = (k + 1);
  if((k >= (nelua_vector_UIWindow____len(a_3) + 0))) {
    return (nlmulret_nlboolean_nlint64_engine_gui_gui_UIWindow_ptr){false, 0, ((engine_gui_gui_UIWindow_ptr)NULL)};
  }
  return (nlmulret_nlboolean_nlint64_engine_gui_gui_UIWindow_ptr){true, k, (&(*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_vector_UIWindow____atindex(a_3, nelua_assert_narrow_nlint64_nlusize(k)))))};
}
nlmulret_function_Po1535aji1YbmWk6_nelua_vector_UIWindow__ptr_nlint64 nelua_mipairs_2(nelua_vector_UIWindow__ptr a) {
  return (nlmulret_function_Po1535aji1YbmWk6_nelua_vector_UIWindow__ptr_nlint64){nelua_mipairs_next_1, a, -1};
}
nlmulret_nlboolean_nlint64_engine_gui_gui_Widget_ptr nelua_mipairs_next_2(nelua_vector_Widget__ptr a_4, int64_t k) {
  k = (k + 1);
  if((k >= (nelua_vector_Widget____len(a_4) + 0))) {
    return (nlmulret_nlboolean_nlint64_engine_gui_gui_Widget_ptr){false, 0, ((engine_gui_gui_Widget_ptr)NULL)};
  }
  return (nlmulret_nlboolean_nlint64_engine_gui_gui_Widget_ptr){true, k, (&(*(engine_gui_gui_Widget*)nelua_assert_deref(nelua_vector_Widget____atindex(a_4, nelua_assert_narrow_nlint64_nlusize(k)))))};
}
nlmulret_function_3dp1Cn41EcGHHu18K_nelua_vector_Widget__ptr_nlint64 nelua_mipairs_3(nelua_vector_Widget__ptr a) {
  return (nlmulret_function_3dp1Cn41EcGHHu18K_nelua_vector_Widget__ptr_nlint64){nelua_mipairs_next_2, a, -1};
}
nlmulret_function_jDKmpuEzyNDncrbK_nelua_hashmap_iteratorT_nlpointer nelua_mpairs_1(nelua_hashmap_pointer__GCItem__ptr a) {
  nlmulret_function_jDKmpuEzyNDncrbK_nelua_hashmap_iteratorT_nlpointer _ret_1 = nelua_hashmap_pointer__GCItem____mpairs(a);
  return (nlmulret_function_jDKmpuEzyNDncrbK_nelua_hashmap_iteratorT_nlpointer){_ret_1.r1, _ret_1.r2, _ret_1.r3};
}
bool nelua_span_uint8__empty(nelua_span_uint8_ self) {
  return (self.size == 0);
}
void nelua_assert_line_4(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/span.nelua:92:13: runtime error: ", 52, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n    check(i < self.size, 'index out of range')\n            ^~~~~~~~~~~\n", 72, true);
    nelua_abort();
  }
}
nluint8_ptr nelua_span_uint8____atindex(nelua_span_uint8_ self, uintptr_t i) {
  nelua_assert_line_4((i < self.size), ((nlstring){(uint8_t*)"index out of range", 18}));
  return (&self.data[i]);
}
void nelua_assert_line_5(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/span.nelua:92:13: runtime error: ", 52, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n    check(i < self.size, 'index out of range')\n            ^~~~~~~~~~~\n", 72, true);
    nelua_abort();
  }
}
nlpointer_ptr nelua_span_pointer____atindex(nelua_span_pointer_ self, uintptr_t i) {
  nelua_assert_line_5((i < self.size), ((nlstring){(uint8_t*)"index out of range", 18}));
  return (&self.data[i]);
}
void nelua_assert_line_6(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/span.nelua:92:13: runtime error: ", 52, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n    check(i < self.size, 'index out of range')\n            ^~~~~~~~~~~\n", 72, true);
    nelua_abort();
  }
}
nelua_GCMarkRange_ptr nelua_span_GCMarkRange____atindex(nelua_span_GCMarkRange_ self, uintptr_t i) {
  nelua_assert_line_6((i < self.size), ((nlstring){(uint8_t*)"index out of range", 18}));
  return (&self.data[i]);
}
void nelua_assert_line_7(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/span.nelua:92:13: runtime error: ", 52, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n    check(i < self.size, 'index out of range')\n            ^~~~~~~~~~~\n", 72, true);
    nelua_abort();
  }
}
nlusize_ptr nelua_span_usize____atindex(nelua_span_usize_ self, uintptr_t i) {
  nelua_assert_line_7((i < self.size), ((nlstring){(uint8_t*)"index out of range", 18}));
  return (&self.data[i]);
}
void nelua_assert_line_8(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/span.nelua:92:13: runtime error: ", 52, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n    check(i < self.size, 'index out of range')\n            ^~~~~~~~~~~\n", 72, true);
    nelua_abort();
  }
}
nelua_hashmapnode_pointer__GCItem__ptr nelua_span_hashmapnode_pointer__GCItem_____atindex(nelua_span_hashmapnode_pointer__GCItem__ self, uintptr_t i) {
  nelua_assert_line_8((i < self.size), ((nlstring){(uint8_t*)"index out of range", 18}));
  return (&self.data[i]);
}
void nelua_assert_line_9(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/span.nelua:92:13: runtime error: ", 52, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n    check(i < self.size, 'index out of range')\n            ^~~~~~~~~~~\n", 72, true);
    nelua_abort();
  }
}
engine_event_event_Event_ptr nelua_span_Event____atindex(nelua_span_Event_ self, uintptr_t i) {
  nelua_assert_line_9((i < self.size), ((nlstring){(uint8_t*)"index out of range", 18}));
  return (&self.data[i]);
}
void nelua_assert_line_10(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/span.nelua:92:13: runtime error: ", 52, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n    check(i < self.size, 'index out of range')\n            ^~~~~~~~~~~\n", 72, true);
    nelua_abort();
  }
}
engine_gui_gui_Widget_ptr nelua_span_Widget____atindex(nelua_span_Widget_ self, uintptr_t i) {
  nelua_assert_line_10((i < self.size), ((nlstring){(uint8_t*)"index out of range", 18}));
  return (&self.data[i]);
}
void nelua_assert_line_11(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/span.nelua:92:13: runtime error: ", 52, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n    check(i < self.size, 'index out of range')\n            ^~~~~~~~~~~\n", 72, true);
    nelua_abort();
  }
}
engine_gui_gui_UIWindow_ptr nelua_span_UIWindow____atindex(nelua_span_UIWindow_ self, uintptr_t i) {
  nelua_assert_line_11((i < self.size), ((nlstring){(uint8_t*)"index out of range", 18}));
  return (&self.data[i]);
}
void nelua_memory_spanset_1(nelua_span_usize_ dest, uintptr_t x) {
  for(uintptr_t i = 0U, _end = dest.size; i < _end; i += 1) {
    (*(uintptr_t*)nelua_assert_deref(nelua_span_usize____atindex(dest, i))) = x;
  }
}
void nelua_vector_pointer__clear(nelua_vector_pointer__ptr self) {
  self->size = 0U;
}
void nelua_vector_pointer__destroy(nelua_vector_pointer__ptr self) {
  nelua_GeneralAllocator_spandealloc_1((&self->allocator), self->data);
  self->data = (nelua_span_pointer_){0};
  self->size = 0U;
}
void nelua_assert_line_12(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/vector.nelua:120:17: runtime error: ", 55, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n      check(cap > self.data.size, 'capacity overflow')\n                ^~~~~~~~~~~~~~~~\n", 89, true);
    nelua_abort();
  }
}
void nelua_vectorT_grow(nelua_vector_pointer__ptr self) {
  uintptr_t cap = 1U;
  if(NELUA_LIKELY((self->data.size != 0))) {
    cap = (self->data.size * 2);
    nelua_assert_line_12((cap > self->data.size), ((nlstring){(uint8_t*)"capacity overflow", 17}));
  }
  self->data = nelua_GeneralAllocator_xspanrealloc_1((&self->allocator), self->data, cap);
}
void nelua_vector_pointer__push(nelua_vector_pointer__ptr self, void* v) {
  uintptr_t newsize = (self->size + 1);
  if(NELUA_UNLIKELY((newsize > self->data.size))) {
    nelua_vectorT_grow(self);
  }
  (*(void**)nelua_assert_deref(nelua_span_pointer____atindex(self->data, self->size))) = v;
  self->size = newsize;
}
void nelua_assert_line_13(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/vector.nelua:219:15: runtime error: ", 55, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n    check(pos < self.size, 'position out of bounds')\n              ^~~~~~~~~~~\n", 80, true);
    nelua_abort();
  }
}
nlpointer_ptr nelua_vector_pointer____atindex(nelua_vector_pointer__ptr self, uintptr_t pos) {
  nelua_assert_line_13((pos < self->size), ((nlstring){(uint8_t*)"position out of bounds", 22}));
  return (&(*(void**)nelua_assert_deref(nelua_span_pointer____atindex(self->data, pos))));
}
void nelua_vector_GCMarkRange__destroy(nelua_vector_GCMarkRange__ptr self) {
  nelua_GeneralAllocator_spandealloc_2((&self->allocator), self->data);
  self->data = (nelua_span_GCMarkRange_){0};
  self->size = 0U;
}
void nelua_assert_line_14(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/vector.nelua:120:17: runtime error: ", 55, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n      check(cap > self.data.size, 'capacity overflow')\n                ^~~~~~~~~~~~~~~~\n", 89, true);
    nelua_abort();
  }
}
void nelua_vectorT_grow_1(nelua_vector_GCMarkRange__ptr self) {
  uintptr_t cap = 1U;
  if(NELUA_LIKELY((self->data.size != 0))) {
    cap = (self->data.size * 2);
    nelua_assert_line_14((cap > self->data.size), ((nlstring){(uint8_t*)"capacity overflow", 17}));
  }
  self->data = nelua_GeneralAllocator_xspanrealloc_2((&self->allocator), self->data, cap);
}
void nelua_vector_GCMarkRange__push(nelua_vector_GCMarkRange__ptr self, nelua_GCMarkRange v) {
  uintptr_t newsize = (self->size + 1);
  if(NELUA_UNLIKELY((newsize > self->data.size))) {
    nelua_vectorT_grow_1(self);
  }
  (*(nelua_GCMarkRange*)nelua_assert_deref(nelua_span_GCMarkRange____atindex(self->data, self->size))) = v;
  self->size = newsize;
}
void nelua_assert_line_15(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/vector.nelua:140:21: runtime error: ", 55, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n    check(self.size > 0, 'attempt to pop an empty vector')\n                    ^~~\n", 84, true);
    nelua_abort();
  }
}
nelua_GCMarkRange nelua_vector_GCMarkRange__pop(nelua_vector_GCMarkRange__ptr self) {
  nelua_assert_line_15((self->size > 0), ((nlstring){(uint8_t*)"attempt to pop an empty vector", 30}));
  self->size = (self->size - 1);
  return (*(nelua_GCMarkRange*)nelua_assert_deref(nelua_span_GCMarkRange____atindex(self->data, self->size)));
}
void nelua_assert_line_16(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/vector.nelua:120:17: runtime error: ", 55, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n      check(cap > self.data.size, 'capacity overflow')\n                ^~~~~~~~~~~~~~~~\n", 89, true);
    nelua_abort();
  }
}
void nelua_vectorT_grow_2(nelua_vector_Event__ptr self) {
  uintptr_t cap = 1U;
  if(NELUA_LIKELY((self->data.size != 0))) {
    cap = (self->data.size * 2);
    nelua_assert_line_16((cap > self->data.size), ((nlstring){(uint8_t*)"capacity overflow", 17}));
  }
  self->data = nelua_GCAllocator_xspanrealloc_3((&self->allocator), self->data, cap);
}
void nelua_vector_Event__push(nelua_vector_Event__ptr self, engine_event_event_Event v) {
  uintptr_t newsize = (self->size + 1);
  if(NELUA_UNLIKELY((newsize > self->data.size))) {
    nelua_vectorT_grow_2(self);
  }
  (*(engine_event_event_Event*)nelua_assert_deref(nelua_span_Event____atindex(self->data, self->size))) = v;
  self->size = newsize;
}
void nelua_assert_line_17(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/vector.nelua:219:15: runtime error: ", 55, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n    check(pos < self.size, 'position out of bounds')\n              ^~~~~~~~~~~\n", 80, true);
    nelua_abort();
  }
}
engine_event_event_Event_ptr nelua_vector_Event____atindex(nelua_vector_Event__ptr self, uintptr_t pos) {
  nelua_assert_line_17((pos < self->size), ((nlstring){(uint8_t*)"position out of bounds", 22}));
  return (&(*(engine_event_event_Event*)nelua_assert_deref(nelua_span_Event____atindex(self->data, pos))));
}
intptr_t nelua_vector_Event____len(nelua_vector_Event__ptr self) {
  return (intptr_t)self->size;
}
void nelua_assert_line_18(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/vector.nelua:120:17: runtime error: ", 55, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n      check(cap > self.data.size, 'capacity overflow')\n                ^~~~~~~~~~~~~~~~\n", 89, true);
    nelua_abort();
  }
}
void nelua_vectorT_grow_3(nelua_vector_Widget__ptr self) {
  uintptr_t cap = 1U;
  if(NELUA_LIKELY((self->data.size != 0))) {
    cap = (self->data.size * 2);
    nelua_assert_line_18((cap > self->data.size), ((nlstring){(uint8_t*)"capacity overflow", 17}));
  }
  self->data = nelua_GCAllocator_xspanrealloc_4((&self->allocator), self->data, cap);
}
void nelua_vector_Widget__push(nelua_vector_Widget__ptr self, engine_gui_gui_Widget v) {
  uintptr_t newsize = (self->size + 1);
  if(NELUA_UNLIKELY((newsize > self->data.size))) {
    nelua_vectorT_grow_3(self);
  }
  (*(engine_gui_gui_Widget*)nelua_assert_deref(nelua_span_Widget____atindex(self->data, self->size))) = v;
  self->size = newsize;
}
void nelua_assert_line_19(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/vector.nelua:219:15: runtime error: ", 55, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n    check(pos < self.size, 'position out of bounds')\n              ^~~~~~~~~~~\n", 80, true);
    nelua_abort();
  }
}
engine_gui_gui_Widget_ptr nelua_vector_Widget____atindex(nelua_vector_Widget__ptr self, uintptr_t pos) {
  nelua_assert_line_19((pos < self->size), ((nlstring){(uint8_t*)"position out of bounds", 22}));
  return (&(*(engine_gui_gui_Widget*)nelua_assert_deref(nelua_span_Widget____atindex(self->data, pos))));
}
intptr_t nelua_vector_Widget____len(nelua_vector_Widget__ptr self) {
  return (intptr_t)self->size;
}
void nelua_assert_line_20(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/vector.nelua:120:17: runtime error: ", 55, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n      check(cap > self.data.size, 'capacity overflow')\n                ^~~~~~~~~~~~~~~~\n", 89, true);
    nelua_abort();
  }
}
void nelua_vectorT_grow_5(nelua_vector_UIWindow__ptr self) {
  uintptr_t cap = 1U;
  if(NELUA_LIKELY((self->data.size != 0))) {
    cap = (self->data.size * 2);
    nelua_assert_line_20((cap > self->data.size), ((nlstring){(uint8_t*)"capacity overflow", 17}));
  }
  self->data = nelua_GCAllocator_xspanrealloc_6((&self->allocator), self->data, cap);
}
void nelua_vector_UIWindow__push(nelua_vector_UIWindow__ptr self, engine_gui_gui_UIWindow v) {
  uintptr_t newsize = (self->size + 1);
  if(NELUA_UNLIKELY((newsize > self->data.size))) {
    nelua_vectorT_grow_5(self);
  }
  (*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_span_UIWindow____atindex(self->data, self->size))) = v;
  self->size = newsize;
}
void nelua_assert_line_21(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/vector.nelua:219:15: runtime error: ", 55, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n    check(pos < self.size, 'position out of bounds')\n              ^~~~~~~~~~~\n", 80, true);
    nelua_abort();
  }
}
engine_gui_gui_UIWindow_ptr nelua_vector_UIWindow____atindex(nelua_vector_UIWindow__ptr self, uintptr_t pos) {
  nelua_assert_line_21((pos < self->size), ((nlstring){(uint8_t*)"position out of bounds", 22}));
  return (&(*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_span_UIWindow____atindex(self->data, pos))));
}
intptr_t nelua_vector_UIWindow____len(nelua_vector_UIWindow__ptr self) {
  return (intptr_t)self->size;
}
void* nelua_GeneralAllocator_alloc_1(nelua_GeneralAllocator_ptr self, uintptr_t size, uintptr_t flags) {
  if(NELUA_UNLIKELY((size == 0))) {
    return (void*)NULL;
  }
  return malloc((size_t)size);
}
void* nelua_GeneralAllocator_alloc_2(nelua_GeneralAllocator_ptr self, uintptr_t size, nlniltype flags) {
  if(NELUA_UNLIKELY((size == 0))) {
    return (void*)NULL;
  }
  return malloc((size_t)size);
}
void* nelua_GeneralAllocator_alloc0_1(nelua_GeneralAllocator_ptr self, uintptr_t size, nlniltype flags) {
  if(NELUA_UNLIKELY((size == 0))) {
    return (void*)NULL;
  }
  return calloc((size_t)size, 1U);
}
void* nelua_GeneralAllocator_alloc0_2(nelua_GeneralAllocator_ptr self, uintptr_t size, uintptr_t flags) {
  if(NELUA_UNLIKELY((size == 0))) {
    return (void*)NULL;
  }
  return calloc((size_t)size, 1U);
}
void nelua_GeneralAllocator_dealloc(nelua_GeneralAllocator_ptr self, void* p) {
  if(NELUA_UNLIKELY((p == (void*)NULL))) {
    return;
  }
  free(p);
}
void* nelua_GeneralAllocator_realloc(nelua_GeneralAllocator_ptr self, void* p, uintptr_t newsize, uintptr_t oldsize) {
  if(NELUA_UNLIKELY((newsize == 0))) {
    if(NELUA_LIKELY((p != (void*)NULL))) {
      free(p);
    }
    return (void*)NULL;
  } else if(NELUA_UNLIKELY((newsize == oldsize))) {
    return p;
  }
  return realloc(p, (size_t)newsize);
}
void* nelua_GeneralAllocator_realloc0(nelua_GeneralAllocator_ptr self, void* p, uintptr_t newsize, uintptr_t oldsize) {
  p = nelua_GeneralAllocator_realloc(self, p, newsize, oldsize);
  if(NELUA_LIKELY(((newsize > oldsize) && (p != (void*)NULL)))) {
    nelua_memory_zero((void*)(&((nluint8_arr0_ptr)p)[oldsize]), (newsize - oldsize));
  }
  return p;
}
nelua_span_pointer_ nelua_GeneralAllocator_spanalloc_1(nelua_GeneralAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags) {
  if(NELUA_LIKELY((size > 0))) {
    nlpointer_arr0_ptr data = ((nlpointer_arr0_ptr)nelua_GeneralAllocator_alloc_2(self, (size * 8), NELUA_NIL));
    if(NELUA_LIKELY((data != ((nlpointer_arr0_ptr)NULL)))) {
      return (nelua_span_pointer_){.data = data, .size = size};
    }
  }
  return (nelua_span_pointer_){0};
}
nelua_span_GCMarkRange_ nelua_GeneralAllocator_spanalloc_2(nelua_GeneralAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags) {
  if(NELUA_LIKELY((size > 0))) {
    uintptr_t flags_1 = 262144U;
    nelua_GCMarkRange_arr0_ptr data = ((nelua_GCMarkRange_arr0_ptr)nelua_GeneralAllocator_alloc_1(self, (size * 16), flags_1));
    if(NELUA_LIKELY((data != ((nelua_GCMarkRange_arr0_ptr)NULL)))) {
      return (nelua_span_GCMarkRange_){.data = data, .size = size};
    }
  }
  return (nelua_span_GCMarkRange_){0};
}
nelua_span_usize_ nelua_GeneralAllocator_spanalloc_3(nelua_GeneralAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags) {
  if(NELUA_LIKELY((size > 0))) {
    uintptr_t flags_2 = 262144U;
    nlusize_arr0_ptr data = ((nlusize_arr0_ptr)nelua_GeneralAllocator_alloc_1(self, (size * 8), flags_2));
    if(NELUA_LIKELY((data != ((nlusize_arr0_ptr)NULL)))) {
      return (nelua_span_usize_){.data = data, .size = size};
    }
  }
  return (nelua_span_usize_){0};
}
nelua_span_hashmapnode_pointer__GCItem__ nelua_GeneralAllocator_spanalloc0_1(nelua_GeneralAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags) {
  if(NELUA_LIKELY((size > 0))) {
    nelua_hashmapnode_pointer__GCItem__arr0_ptr data = ((nelua_hashmapnode_pointer__GCItem__arr0_ptr)nelua_GeneralAllocator_alloc0_1(self, (size * 64), NELUA_NIL));
    if(NELUA_LIKELY((data != ((nelua_hashmapnode_pointer__GCItem__arr0_ptr)NULL)))) {
      return (nelua_span_hashmapnode_pointer__GCItem__){.data = data, .size = size};
    }
  }
  return (nelua_span_hashmapnode_pointer__GCItem__){0};
}
void nelua_GeneralAllocator_spandealloc_1(nelua_GeneralAllocator_ptr self, nelua_span_pointer_ s) {
  if(NELUA_UNLIKELY((s.size == 0))) {
    return;
  }
  nelua_GeneralAllocator_dealloc(self, (void*)s.data);
}
void nelua_GeneralAllocator_spandealloc_2(nelua_GeneralAllocator_ptr self, nelua_span_GCMarkRange_ s) {
  if(NELUA_UNLIKELY((s.size == 0))) {
    return;
  }
  nelua_GeneralAllocator_dealloc(self, (void*)s.data);
}
void nelua_GeneralAllocator_spandealloc_3(nelua_GeneralAllocator_ptr self, nelua_span_usize_ s) {
  if(NELUA_UNLIKELY((s.size == 0))) {
    return;
  }
  nelua_GeneralAllocator_dealloc(self, (void*)s.data);
}
void nelua_GeneralAllocator_spandealloc_4(nelua_GeneralAllocator_ptr self, nelua_span_hashmapnode_pointer__GCItem__ s) {
  if(NELUA_UNLIKELY((s.size == 0))) {
    return;
  }
  nelua_GeneralAllocator_dealloc(self, (void*)s.data);
}
nelua_span_pointer_ nelua_GeneralAllocator_spanrealloc_1(nelua_GeneralAllocator_ptr self, nelua_span_pointer_ s, uintptr_t size) {
  if(NELUA_UNLIKELY(((s.size == 0) && (size > 0)))) {
    s = nelua_GeneralAllocator_spanalloc_1(self, NELUA_NIL, size, NELUA_NIL);
    return s;
  }
  nlpointer_arr0_ptr p = ((nlpointer_arr0_ptr)nelua_GeneralAllocator_realloc(self, (void*)s.data, (size * 8), (s.size * 8)));
  if(NELUA_UNLIKELY(((size > 0) && (p == ((nlpointer_arr0_ptr)NULL))))) {
    return s;
  }
  s.data = p;
  s.size = size;
  return s;
}
nelua_span_GCMarkRange_ nelua_GeneralAllocator_spanrealloc_2(nelua_GeneralAllocator_ptr self, nelua_span_GCMarkRange_ s, uintptr_t size) {
  if(NELUA_UNLIKELY(((s.size == 0) && (size > 0)))) {
    s = nelua_GeneralAllocator_spanalloc_2(self, NELUA_NIL, size, NELUA_NIL);
    return s;
  }
  nelua_GCMarkRange_arr0_ptr p = ((nelua_GCMarkRange_arr0_ptr)nelua_GeneralAllocator_realloc(self, (void*)s.data, (size * 16), (s.size * 16)));
  if(NELUA_UNLIKELY(((size > 0) && (p == ((nelua_GCMarkRange_arr0_ptr)NULL))))) {
    return s;
  }
  s.data = p;
  s.size = size;
  return s;
}
nelua_span_usize_ nelua_GeneralAllocator_spanrealloc_3(nelua_GeneralAllocator_ptr self, nelua_span_usize_ s, uintptr_t size) {
  if(NELUA_UNLIKELY(((s.size == 0) && (size > 0)))) {
    s = nelua_GeneralAllocator_spanalloc_3(self, NELUA_NIL, size, NELUA_NIL);
    return s;
  }
  nlusize_arr0_ptr p = ((nlusize_arr0_ptr)nelua_GeneralAllocator_realloc(self, (void*)s.data, (size * 8), (s.size * 8)));
  if(NELUA_UNLIKELY(((size > 0) && (p == ((nlusize_arr0_ptr)NULL))))) {
    return s;
  }
  s.data = p;
  s.size = size;
  return s;
}
void nelua_panic_string(nlstring s) {
  if(s.size > 0) {
    nelua_write_stderr((const char*)s.data, s.size, true);
  }
  nelua_abort();
}
nelua_span_pointer_ nelua_GeneralAllocator_xspanrealloc_1(nelua_GeneralAllocator_ptr self, nelua_span_pointer_ s, uintptr_t size) {
  s = nelua_GeneralAllocator_spanrealloc_1(self, s, size);
  if(NELUA_UNLIKELY((s.size != size))) {
    nelua_panic_string(((nlstring){(uint8_t*)"out of memory", 13}));
  }
  return s;
}
nelua_span_GCMarkRange_ nelua_GeneralAllocator_xspanrealloc_2(nelua_GeneralAllocator_ptr self, nelua_span_GCMarkRange_ s, uintptr_t size) {
  s = nelua_GeneralAllocator_spanrealloc_2(self, s, size);
  if(NELUA_UNLIKELY((s.size != size))) {
    nelua_panic_string(((nlstring){(uint8_t*)"out of memory", 13}));
  }
  return s;
}
nelua_span_usize_ nelua_GeneralAllocator_xspanrealloc_3(nelua_GeneralAllocator_ptr self, nelua_span_usize_ s, uintptr_t size) {
  s = nelua_GeneralAllocator_spanrealloc_3(self, s, size);
  if(NELUA_UNLIKELY((s.size != size))) {
    nelua_panic_string(((nlstring){(uint8_t*)"out of memory", 13}));
  }
  return s;
}
nelua_span_hashmapnode_pointer__GCItem__ nelua_GeneralAllocator_spanrealloc0_1(nelua_GeneralAllocator_ptr self, nelua_span_hashmapnode_pointer__GCItem__ s, uintptr_t size) {
  if(NELUA_UNLIKELY(((s.size == 0) && (size > 0)))) {
    s = nelua_GeneralAllocator_spanalloc0_1(self, NELUA_NIL, size, NELUA_NIL);
    return s;
  }
  nelua_hashmapnode_pointer__GCItem__arr0_ptr p = ((nelua_hashmapnode_pointer__GCItem__arr0_ptr)nelua_GeneralAllocator_realloc0(self, (void*)s.data, (size * 64), (s.size * 64)));
  if(NELUA_UNLIKELY(((size > 0) && (p == ((nelua_hashmapnode_pointer__GCItem__arr0_ptr)NULL))))) {
    return s;
  }
  s.data = p;
  s.size = size;
  return s;
}
nelua_span_hashmapnode_pointer__GCItem__ nelua_GeneralAllocator_xspanrealloc0_1(nelua_GeneralAllocator_ptr self, nelua_span_hashmapnode_pointer__GCItem__ s, uintptr_t size) {
  s = nelua_GeneralAllocator_spanrealloc0_1(self, s, size);
  if(NELUA_UNLIKELY((s.size != size))) {
    nelua_panic_string(((nlstring){(uint8_t*)"out of memory", 13}));
  }
  return s;
}
uintptr_t nelua_hash_hash_1(void* v) {
  return ((uintptr_t)v >> 3);
}
uintptr_t nelua_ceilidiv(uintptr_t x, uintptr_t y) {
  return (((x + y) - 1) / y);
}
uintptr_t nelua_hashmod(uintptr_t h, uintptr_t n) {
  return (h % ((n - 1) | 1));
}
uintptr_t nelua_roundpow2(uintptr_t n) {
  if(((n & (n - 1)) == 0)) {
    return n;
  }
  n = (n | (n >> 1));
  n = (n | (n >> 2));
  n = (n | (n >> 4));
  n = (n | (n >> 8));
  n = (n | (n >> 16));
  n = (n | (n >> 32));
  n = (n + 1);
  return n;
}
void nelua_hashmap_pointer__GCItem__destroy(nelua_hashmap_pointer__GCItem__ptr self) {
  nelua_GeneralAllocator_spandealloc_3((&self->allocator), self->buckets);
  nelua_GeneralAllocator_spandealloc_4((&self->allocator), self->nodes);
  self->buckets = (nelua_span_usize_){0};
  self->nodes = (nelua_span_hashmapnode_pointer__GCItem__){0};
  self->size = 0U;
  self->free_index = 0U;
}
nlmulret_nlusize_nlusize_nlusize nelua_hashmap_pointer__GCItem___find(nelua_hashmap_pointer__GCItem__ptr self, void* key) {
  uintptr_t h = nelua_hash_hash_1(key);
  uintptr_t bucket_index = nelua_hashmod(h, self->buckets.size);
  uintptr_t prev_node_index = 0xffffffffffffffffULL;
  if(NELUA_UNLIKELY((self->buckets.size == 0))) {
    return (nlmulret_nlusize_nlusize_nlusize){0xffffffffffffffffULL, prev_node_index, bucket_index};
  }
  uintptr_t node_index = (*(uintptr_t*)nelua_assert_deref(nelua_span_usize____atindex(self->buckets, bucket_index)));
  while((node_index != 0xffffffffffffffffULL)) {
    nelua_hashmapnode_pointer__GCItem__ptr node = (&(*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->nodes, node_index))));
    bool eq = (key == node->key);
    if(eq) {
      return (nlmulret_nlusize_nlusize_nlusize){node_index, prev_node_index, bucket_index};
    }
    prev_node_index = node_index;
    node_index = node->next;
  }
  return (nlmulret_nlusize_nlusize_nlusize){node_index, prev_node_index, bucket_index};
}
void nelua_assert_line_22(bool cond) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/hashmap.nelua:212:15: runtime error: assertion failed!\n      check(j == self.size)\n              ^~~~~~~~~~~~\n",  129, true);
    nelua_abort();
  }
}
void nelua_hashmap_pointer__GCItem__rehash(nelua_hashmap_pointer__GCItem__ptr self, uintptr_t bucket_count) {
  uintptr_t min_buckets_count = nelua_ceilidiv((self->size * 100), 75U);
  if((bucket_count < min_buckets_count)) {
    bucket_count = min_buckets_count;
  }
  bucket_count = nelua_roundpow2(bucket_count);
  uintptr_t node_count = nelua_ceilidiv((bucket_count * 75U), 100U);
  if(((bucket_count > 0) && (node_count <= self->size))) {
    node_count = (self->size + 1);
  }
  if((((node_count < self->nodes.size) && (self->nodes.size > 0)) && (node_count > 0))) {
    uintptr_t j = 0U;
    while(((j < self->nodes.size) && (*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->nodes, j))).filled)) {
      j = (j + 1);
    }
    for(uintptr_t i = j, _end = self->nodes.size; i < _end; i += 1) {
      if((*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->nodes, i))).filled) {
        (*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->nodes, j))) = (*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->nodes, i)));
        j = (j + 1);
      }
    }
    for(uintptr_t i = j, _end = self->nodes.size; i < _end; i += 1) {
      (*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->nodes, i))) = (nelua_hashmapnode_pointer__GCItem_){0};
    }
    nelua_assert_line_22((j == self->size));
  }
  self->nodes = nelua_GeneralAllocator_xspanrealloc0_1((&self->allocator), self->nodes, node_count);
  self->buckets = nelua_GeneralAllocator_xspanrealloc_3((&self->allocator), self->buckets, bucket_count);
  nelua_memory_spanset_1(self->buckets, 0xffffffffffffffffULL);
  uintptr_t free_index = 0xffffffffffffffffULL;
  for(intptr_t i = (intptr_t)(self->nodes.size - 1); i >= 0; i += -1) {
    nelua_hashmapnode_pointer__GCItem__ptr node = (&(*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->nodes, (uintptr_t)i))));
    if(node->filled) {
      node->next = 0xffffffffffffffffULL;
    } else {
      node->next = free_index;
      free_index = (uintptr_t)i;
    }
  }
  self->free_index = free_index;
  for(uintptr_t i = 0U, _end = self->nodes.size; i < _end; i += 1) {
    if((*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->nodes, i))).filled) {
      nlmulret_nlusize_nlusize_nlusize _asgnret_1 = nelua_hashmap_pointer__GCItem___find(self, (*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->nodes, i))).key);
      uintptr_t node_index = _asgnret_1.r1;
      uintptr_t prev_node_index = _asgnret_1.r2;
      uintptr_t bucket_index = _asgnret_1.r3;
      if(NELUA_LIKELY((prev_node_index == 0xffffffffffffffffULL))) {
        (*(uintptr_t*)nelua_assert_deref(nelua_span_usize____atindex(self->buckets, bucket_index))) = i;
      } else {
        (*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->nodes, prev_node_index))).next = i;
      }
      (*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->nodes, i))).next = node_index;
    }
  }
}
void nelua_assert_line_23(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/hashmap.nelua:268:24: runtime error: ", 56, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n      check(node_index < self.nodes.size, 'not enough space to add a node')\n                       ^~~~~~~~~~~~~~~~~\n", 118, true);
    nelua_abort();
  }
}
uintptr_t nelua_hashmap_pointer__GCItem___at(nelua_hashmap_pointer__GCItem__ptr self, void* key) {
  if(NELUA_UNLIKELY((self->buckets.size == 0))) {
    nelua_hashmap_pointer__GCItem__rehash(self, 8U);
  }
  nlmulret_nlusize_nlusize_nlusize _asgnret_1 = nelua_hashmap_pointer__GCItem___find(self, key);
  uintptr_t node_index = _asgnret_1.r1;
  uintptr_t prev_node_index = _asgnret_1.r2;
  uintptr_t bucket_index = _asgnret_1.r3;
  if((node_index != 0xffffffffffffffffULL)) {
    return node_index;
  } else {
    uintptr_t node_index_1 = self->free_index;
    nelua_assert_line_23((node_index_1 < self->nodes.size), ((nlstring){(uint8_t*)"not enough space to add a node", 30}));
    nelua_hashmapnode_pointer__GCItem__ptr node = (&(*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->nodes, node_index_1))));
    self->free_index = node->next;
    (*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(node)) = (nelua_hashmapnode_pointer__GCItem_){.key = key, .filled = true, .next = 0xffffffffffffffffULL};
    if(NELUA_LIKELY((prev_node_index == 0xffffffffffffffffULL))) {
      (*(uintptr_t*)nelua_assert_deref(nelua_span_usize____atindex(self->buckets, bucket_index))) = node_index_1;
    } else {
      (*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->nodes, prev_node_index))).next = node_index_1;
    }
    self->size = (self->size + 1);
    if(NELUA_UNLIKELY(((self->size * 100) >= (self->buckets.size * 75U)))) {
      nelua_hashmap_pointer__GCItem__rehash(self, nelua_ceilidiv((self->size * 200U), 75U));
    }
    return node_index_1;
  }
}
nelua_GCItem_ptr nelua_hashmap_pointer__GCItem____atindex(nelua_hashmap_pointer__GCItem__ptr self, void* key) {
  return (&(*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->nodes, nelua_hashmap_pointer__GCItem___at(self, key)))).value);
}
nelua_GCItem_ptr nelua_hashmap_pointer__GCItem__peek(nelua_hashmap_pointer__GCItem__ptr self, void* key) {
  uintptr_t node_index = nelua_hashmap_pointer__GCItem___find(self, key).r1;
  if((node_index != 0xffffffffffffffffULL)) {
    return (&(*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->nodes, node_index))).value);
  }
  return ((nelua_GCItem_ptr)NULL);
}
nelua_GCItem nelua_hashmap_pointer__GCItem__remove(nelua_hashmap_pointer__GCItem__ptr self, void* key) {
  nlmulret_nlusize_nlusize_nlusize _asgnret_1 = nelua_hashmap_pointer__GCItem___find(self, key);
  uintptr_t node_index = _asgnret_1.r1;
  uintptr_t prev_node_index = _asgnret_1.r2;
  uintptr_t bucket_index = _asgnret_1.r3;
  if(NELUA_UNLIKELY((node_index == 0xffffffffffffffffULL))) {
    return (nelua_GCItem){0};
  }
  nelua_hashmapnode_pointer__GCItem__ptr node = (&(*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->nodes, node_index))));
  nelua_GCItem value = node->value;
  if(NELUA_LIKELY((prev_node_index == 0xffffffffffffffffULL))) {
    (*(uintptr_t*)nelua_assert_deref(nelua_span_usize____atindex(self->buckets, bucket_index))) = node->next;
  } else {
    (*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->nodes, prev_node_index))).next = node->next;
  }
  self->size = (self->size - 1);
  (*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(node)) = (nelua_hashmapnode_pointer__GCItem_){.next = self->free_index};
  self->free_index = node_index;
  return value;
}
uintptr_t nelua_hashmap_pointer__GCItem__bucketcount(nelua_hashmap_pointer__GCItem__ptr self) {
  return self->buckets.size;
}
nelua_hashmapnode_pointer__GCItem__ptr nelua_hashmap_iteratorT__next_node(nelua_hashmap_iteratorT_ptr self, void* key) {
  if(NELUA_UNLIKELY((self->index == 0xffffffffffffffffULL))) {
    self->index = 0U;
  } else {
    self->index = (self->index + 1);
  }
  while((self->index < self->container->nodes.size)) {
    nelua_hashmapnode_pointer__GCItem__ptr node = (&(*(nelua_hashmapnode_pointer__GCItem_*)nelua_assert_deref(nelua_span_hashmapnode_pointer__GCItem_____atindex(self->container->nodes, self->index))));
    if(node->filled) {
      return node;
    }
    self->index = (self->index + 1);
  }
  return ((nelua_hashmapnode_pointer__GCItem__ptr)NULL);
}
nlmulret_nlboolean_nlpointer_nelua_GCItem_ptr nelua_hashmap_iteratorT_mnext(nelua_hashmap_iteratorT_ptr self, void* key) {
  nelua_hashmapnode_pointer__GCItem__ptr node = nelua_hashmap_iteratorT__next_node(self, key);
  if((!(node != NULL))) {
    return (nlmulret_nlboolean_nlpointer_nelua_GCItem_ptr){false, NULL, ((nelua_GCItem_ptr)NULL)};
  }
  return (nlmulret_nlboolean_nlpointer_nelua_GCItem_ptr){true, node->key, (&node->value)};
}
nlmulret_function_jDKmpuEzyNDncrbK_nelua_hashmap_iteratorT_nlpointer nelua_hashmap_pointer__GCItem____mpairs(nelua_hashmap_pointer__GCItem__ptr self) {
  return (nlmulret_function_jDKmpuEzyNDncrbK_nelua_hashmap_iteratorT_nlpointer){nelua_hashmap_iteratorT_mnext, (nelua_hashmap_iteratorT){.container = self, .index = 0xffffffffffffffffULL}, NULL};
}
bool nelua_hasflag(uintptr_t flags, uintptr_t flag) {
  return ((flags & flag) != 0);
}
uintptr_t nelua_align_forward(uintptr_t addr, uintptr_t align) {
  return ((addr + (align - 1)) & (~(align - 1)));
}
bool nelua_GCItem_ismarked(nelua_GCItem_ptr self) {
  return nelua_hasflag(self->flags, 196608U);
}
void nelua_assert_line_24(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/allocators/gc.nelua:127:19: runtime error: ", 62, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n  assert(item.ptr == ptr, 'invalid unregister pointer')\n                  ^~~~~~\n", 82, true);
    nelua_abort();
  }
}
void nelua_GC_unregister_1(nelua_GC_ptr self, void* ptr, bool finalize) {
  if(NELUA_UNLIKELY((!(ptr != NULL)))) {
    return;
  }
  nelua_GCItem item = nelua_hashmap_pointer__GCItem__remove((&self->items), ptr);
  nelua_assert_line_24((item.ptr == ptr), ((nlstring){(uint8_t*)"invalid unregister pointer", 26}));
  if((!nelua_hasflag(item.flags, 131072U))) {
    self->membytes = (self->membytes - item.size);
    for(uintptr_t i = 0U, _end = self->frees.size; i < _end; i += 1) {
      if(((*(void**)nelua_assert_deref(nelua_vector_pointer____atindex((&self->frees), i))) == ptr)) {
        (*(void**)nelua_assert_deref(nelua_vector_pointer____atindex((&self->frees), i))) = (void*)NULL;
        break;
      }
    }
  }
  if((finalize && (item.finalizer != NULL))) {
    item.finalizer(ptr, item.userdata);
  }
}
void nelua_GC_markptrs(nelua_GC_ptr self, uintptr_t low, uintptr_t high) {
  uintptr_t minaddr = self->minaddr;
  uintptr_t maxaddr = self->maxaddr;
  nelua_hashmap_pointer__GCItem__ptr items = (&self->items);
  nelua_vector_GCMarkRange__push((&self->markranges), (nelua_GCMarkRange){low, high});
  while((self->markranges.size > 0)) {
    nelua_GCMarkRange range = nelua_vector_GCMarkRange__pop((&self->markranges));
    for(uintptr_t memaddr = range.low, _end = range.high; memaddr < _end; memaddr += 8) {
      uintptr_t addr = (*(uintptr_t*)nelua_assert_deref((nlusize_ptr)memaddr));
      if(((addr >= minaddr) && (addr <= maxaddr))) {
        nelua_GCItem_ptr item = nelua_hashmap_pointer__GCItem__peek(items, (void*)addr);
        if(((item != NULL) && (!nelua_GCItem_ismarked(item)))) {
          item->flags = (item->flags | 65536U);
          if((!nelua_hasflag(item->flags, 262144U))) {
            nelua_vector_GCMarkRange__push((&self->markranges), (nelua_GCMarkRange){addr, (addr + item->size)});
          }
        }
      }
    }
  }
}
void nelua_GC_markptr(nelua_GC_ptr self, void* ptr) {
  nelua_GCItem_ptr item = nelua_hashmap_pointer__GCItem__peek((&self->items), ptr);
  if(((item != NULL) && (!nelua_GCItem_ismarked(item)))) {
    item->flags = (item->flags | 65536U);
    if((!nelua_hasflag(item->flags, 262144U))) {
      uintptr_t addr = (uintptr_t)ptr;
      nelua_GC_markptrs(self, addr, (addr + item->size));
    }
  }
}
void nelua_GC_unmarkall(nelua_GC_ptr self) {
  {
    nlmulret_function_jDKmpuEzyNDncrbK_nelua_hashmap_iteratorT_nlpointer _asgnret_1 = nelua_mpairs_1((&self->items));
    function_jDKmpuEzyNDncrbK __fornext = _asgnret_1.r1;
    nelua_hashmap_iteratorT __forstate = _asgnret_1.r2;
    void* __fornextit = _asgnret_1.r3;
    while(true) {
      nlmulret_nlboolean_nlpointer_nelua_GCItem_ptr _asgnret_2 = __fornext((&__forstate), __fornextit);
      bool __forcont = _asgnret_2.r1;
      void* ptr = _asgnret_2.r2;
      nelua_GCItem_ptr item = _asgnret_2.r3;
      if((!__forcont)) {
        break;
      }
      __fornextit = ptr;
      {
        item->flags = (item->flags & 18446744073709486079ULL);
      }
    }
  }
}
void nelua_GC_markroot(nelua_GC_ptr self) {
  {
    nlmulret_function_jDKmpuEzyNDncrbK_nelua_hashmap_iteratorT_nlpointer _asgnret_1 = nelua_mpairs_1((&self->items));
    function_jDKmpuEzyNDncrbK __fornext = _asgnret_1.r1;
    nelua_hashmap_iteratorT __forstate = _asgnret_1.r2;
    void* __fornextit = _asgnret_1.r3;
    while(true) {
      nlmulret_nlboolean_nlpointer_nelua_GCItem_ptr _asgnret_2 = __fornext((&__forstate), __fornextit);
      bool __forcont = _asgnret_2.r1;
      void* ptr = _asgnret_2.r2;
      nelua_GCItem_ptr item = _asgnret_2.r3;
      if((!__forcont)) {
        break;
      }
      __fornextit = ptr;
      {
        if(nelua_hasflag(item->flags, 131072U)) {
          uintptr_t addr = (uintptr_t)ptr;
          nelua_GC_markptrs(self, addr, (addr + item->size));
        }
      }
    }
  }
}
void nelua_GC_markstack(nelua_GC_ptr self) {
  nelua_RegsBuf regsbuf;
  setjmp(regsbuf.regs);
#if defined(__GNUC__) || defined(__clang__)
  void* sp = __builtin_frame_address(0);
#endif
  uintptr_t low = ((self->stacktop == 0) ? (uintptr_t)(&regsbuf) : self->stacktop);
  uintptr_t high = self->stackbottom;
  if((high < low)) {
    uintptr_t _asgntmp_1 = high;
    uintptr_t _asgntmp_2 = low;
    low = _asgntmp_1;
    high = _asgntmp_2;
  }
  low = nelua_align_forward(low, 8U);
  nelua_GC_markptrs(self, low, high);
  nelua_GC_markptrs(self, (uintptr_t)(&regsbuf), ((uintptr_t)(&regsbuf) + (uintptr_t)sizeof(nelua_RegsBuf)));
#if defined(__GNUC__) || defined(__clang__)
  nelua_GC_markptr(self, sp);
#endif
}
void nelua_GC_mark(nelua_GC_ptr self) {
  nelua_GC_unmarkall(self);
  nelua_GC_markroot(self);
  if((self->stackbottom != 0)) {
    volatile function_5F616zmeWxFHshuob markstack = nelua_GC_markstack;
    markstack(self);
  }
}
void nelua_assert_line_25(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/allocators/gc.nelua:261:20: runtime error: ", 62, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n        check(item ~= nilptr, 'gc item not found to finalize')\n                   ^~~~~~~~~\n", 93, true);
    nelua_abort();
  }
}
void nelua_assert_line_26(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/allocators/gc.nelua:277:22: runtime error: ", 62, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n      check(item.ptr == ptr, 'gc item not found to deallocate')\n                     ^~~~~~\n", 93, true);
    nelua_abort();
  }
}
void nelua_GC_sweep(nelua_GC_ptr self) {
  bool finalize = false;
  {
    nlmulret_function_jDKmpuEzyNDncrbK_nelua_hashmap_iteratorT_nlpointer _asgnret_1 = nelua_mpairs_1((&self->items));
    function_jDKmpuEzyNDncrbK __fornext = _asgnret_1.r1;
    nelua_hashmap_iteratorT __forstate = _asgnret_1.r2;
    void* __fornextit = _asgnret_1.r3;
    while(true) {
      nlmulret_nlboolean_nlpointer_nelua_GCItem_ptr _asgnret_2 = __fornext((&__forstate), __fornextit);
      bool __forcont = _asgnret_2.r1;
      void* ptr = _asgnret_2.r2;
      nelua_GCItem_ptr item = _asgnret_2.r3;
      if((!__forcont)) {
        break;
      }
      __fornextit = ptr;
      {
        if((!nelua_GCItem_ismarked(item))) {
          nelua_vector_pointer__push((&self->frees), ptr);
          if(((!finalize) && (item->finalizer != NULL))) {
            finalize = true;
          }
        }
      }
    }
  }
  if(finalize) {
    uintptr_t i = 0U;
    while((i < self->frees.size)) {
      void* ptr = (*(void**)nelua_assert_deref(nelua_vector_pointer____atindex((&self->frees), i)));
      if((ptr != NULL)) {
        nelua_GCItem_ptr item = nelua_hashmap_pointer__GCItem__peek((&self->items), ptr);
        nelua_assert_line_25((item != ((nelua_GCItem_ptr)NULL)), ((nlstring){(uint8_t*)"gc item not found to finalize", 29}));
        if(((item != NULL) && (item->finalizer != NULL))) {
          nelua_GCFinalizerCallback finalizer = item->finalizer;
          item->finalizer = (nelua_GCFinalizerCallback)NULL;
          finalizer(ptr, item->userdata);
        }
      }
      i = (i + 1);
    }
  }
  uintptr_t i = 0U;
  while((i < self->frees.size)) {
    void* ptr = (*(void**)nelua_assert_deref(nelua_vector_pointer____atindex((&self->frees), i)));
    if((ptr != NULL)) {
      nelua_GCItem item = nelua_hashmap_pointer__GCItem__remove((&self->items), ptr);
      nelua_assert_line_26((item.ptr == ptr), ((nlstring){(uint8_t*)"gc item not found to deallocate", 31}));
      if((item.ptr != NULL)) {
        self->membytes = (self->membytes - item.size);
        if((!nelua_hasflag(item.flags, 1048576U))) {
          nelua_GeneralAllocator_dealloc((&nelua_general_allocator), ptr);
        }
      }
    }
    i = (i + 1);
  }
  nelua_vector_pointer__clear((&self->frees));
}
void nelua_GC_collect(nelua_GC_ptr self) {
  if((self->collecting || (self->membytes == 0))) {
    return;
  }
  self->collecting = true;
  nelua_GC_mark(self);
  nelua_GC_sweep(self);
  self->lastmembytes = self->membytes;
  if(((self->items.size * 4) < nelua_hashmap_pointer__GCItem__bucketcount((&self->items)))) {
    nelua_hashmap_pointer__GCItem__rehash((&self->items), 0U);
  }
  self->collecting = false;
}
void nelua_GC_registerroots(nelua_GC_ptr self) {
  nelua_GC_register((&nelua_gc), (void*)(&engine_mouse_mouse_Mouse), 40U, 131072U, (function_4cJAvFfHJEMFkKdi7)NULL, (void*)NULL);
  nelua_GC_register((&nelua_gc), (void*)(&engine_event_manager_event_manager_EventManager), 24U, 131072U, (function_4cJAvFfHJEMFkKdi7)NULL, (void*)NULL);
  nelua_GC_register((&nelua_gc), (void*)(&engine_uimanager_uimanager_UIManager), 32U, 131072U, (function_4cJAvFfHJEMFkKdi7)NULL, (void*)NULL);
}
bool nelua_GC_step(nelua_GC_ptr self) {
  if(((!self->collecting) && ((self->membytes * 100) >= (self->lastmembytes * self->pause)))) {
    nelua_GC_collect(self);
    return true;
  }
  return false;
}
void nelua_assert_line_27(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/allocators/gc.nelua:382:18: runtime error: ", 62, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n  check(item.ptr == nilptr, 'cannot register pointer twice')\n                 ^~~~~~~~~\n", 89, true);
    nelua_abort();
  }
}
void nelua_GC_register(nelua_GC_ptr self, void* ptr, uintptr_t size, uintptr_t flags, function_4cJAvFfHJEMFkKdi7 finalizer, void* userdata) {
  if(NELUA_UNLIKELY((!(ptr != NULL)))) {
    return;
  }
  if(NELUA_UNLIKELY((size < 8))) {
    flags = (flags | 262144U);
  }
  nelua_GCItem_ptr item = (&(*(nelua_GCItem*)nelua_assert_deref(nelua_hashmap_pointer__GCItem____atindex((&self->items), ptr))));
  nelua_assert_line_27((item->ptr == (void*)NULL), ((nlstring){(uint8_t*)"cannot register pointer twice", 29}));
  (*(nelua_GCItem*)nelua_assert_deref(item)) = (nelua_GCItem){.flags = flags, .size = size, .ptr = ptr, .finalizer = finalizer, .userdata = userdata};
  if(NELUA_LIKELY((!nelua_hasflag(flags, 131072U)))) {
    uintptr_t addr = (uintptr_t)ptr;
    uintptr_t addrhigh = (addr + size);
    if((addrhigh > self->maxaddr)) {
      self->maxaddr = addrhigh;
    }
    if((addr < self->minaddr)) {
      self->minaddr = addr;
    }
    self->membytes = (self->membytes + size);
    if(self->running) {
      nelua_GC_step(self);
    }
  }
}
void nelua_assert_line_28(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/allocators/gc.nelua:409:47: runtime error: ", 62, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n  check(oldptr ~= nilptr and newptr ~= nilptr and newsize > 0, 'invalid reregister arguments')\n                                              ^~~~~~~~~~~~~~~\n", 158, true);
    nelua_abort();
  }
}
void nelua_assert_line_29(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/allocators/gc.nelua:413:17: runtime error: ", 62, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n    assert(item ~= nilptr, 'invalid reregister pointer')\n                ^~~~~~~~~\n", 84, true);
    nelua_abort();
  }
}
void nelua_assert_line_30(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/allocators/gc.nelua:428:21: runtime error: ", 62, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n    assert(item.ptr ~= nilptr, 'invalid reregister pointer')\n                    ^~~~~~~~~\n", 92, true);
    nelua_abort();
  }
}
void nelua_GC_reregister(nelua_GC_ptr self, void* oldptr, void* newptr, uintptr_t newsize) {
  nelua_assert_line_28((((oldptr != (void*)NULL) && (newptr != (void*)NULL)) && (newsize > 0)), ((nlstring){(uint8_t*)"invalid reregister arguments", 28}));
  uintptr_t oldsize = 0U;
  if((newptr == oldptr)) {
    nelua_GCItem_ptr item = nelua_hashmap_pointer__GCItem__peek((&self->items), oldptr);
    nelua_assert_line_29((item != ((nelua_GCItem_ptr)NULL)), ((nlstring){(uint8_t*)"invalid reregister pointer", 26}));
    oldsize = item->size;
    item->size = newsize;
    if(NELUA_LIKELY((!nelua_hasflag(item->flags, 131072U)))) {
      if((newsize > oldsize)) {
        self->membytes = (self->membytes + (newsize - oldsize));
        if(self->running) {
          nelua_GC_step(self);
        }
      } else if((newsize < oldsize)) {
        self->membytes = (self->membytes - (oldsize - newsize));
      }
    }
  } else {
    nelua_GCItem item = nelua_hashmap_pointer__GCItem__remove((&self->items), oldptr);
    nelua_assert_line_30((item.ptr != (void*)NULL), ((nlstring){(uint8_t*)"invalid reregister pointer", 26}));
    oldsize = item.size;
    if(NELUA_LIKELY((!nelua_hasflag(item.flags, 131072U)))) {
      self->membytes = (self->membytes - oldsize);
      for(uintptr_t i = 0U, _end = self->frees.size; i < _end; i += 1) {
        if(((*(void**)nelua_assert_deref(nelua_vector_pointer____atindex((&self->frees), i))) == oldptr)) {
          (*(void**)nelua_assert_deref(nelua_vector_pointer____atindex((&self->frees), i))) = newptr;
          break;
        }
      }
    }
    nelua_GC_register(self, newptr, newsize, item.flags, item.finalizer, item.userdata);
  }
}
void nelua_GC_restart(nelua_GC_ptr self) {
  self->running = true;
}
void nelua_GC_init(nelua_GC_ptr self, void* stack) {
  self->stackbottom = (uintptr_t)stack;
  self->minaddr = 0xffffffffffffffffULL;
  self->pause = 200U;
  nelua_GC_registerroots(self);
  nelua_GC_restart(self);
}
void nelua_GC_destroy(nelua_GC_ptr self) {
  nelua_GC_unmarkall(self);
  nelua_GC_sweep(self);
  nelua_hashmap_pointer__GCItem__destroy((&self->items));
  nelua_vector_pointer__destroy((&self->frees));
  nelua_vector_GCMarkRange__destroy((&self->markranges));
  (*(nelua_GC*)nelua_assert_deref(self)) = (nelua_GC){0};
}
int main(int argc, nlcstring_ptr argv) {
  nelua_GC_init((&nelua_gc), (void*)(&argc));
  volatile function_3vE21UhnrxvrKKPii inner_main = nelua_main;
  int ret = inner_main(argc, argv);
  nelua_GC_destroy((&nelua_gc));
  return ret;
}
void* nelua_GCAllocator_alloc_1(nelua_GCAllocator_ptr self, uintptr_t size, nlniltype flags, nlniltype finalizer, nlniltype userdata) {
  if(NELUA_UNLIKELY((size == 0))) {
    return (void*)NULL;
  }
  uintptr_t flags_3 = 0U;
  nelua_GCFinalizerCallback finalizer_1 = (nelua_GCFinalizerCallback)NULL;
  void* userdata_1 = (void*)NULL;
  void* ptr = nelua_GeneralAllocator_alloc_1((&nelua_general_allocator), size, flags_3);
  nelua_GC_register((&nelua_gc), ptr, size, flags_3, finalizer_1, userdata_1);
  return ptr;
}
void* nelua_GCAllocator_alloc_2(nelua_GCAllocator_ptr self, uintptr_t size, nlniltype flags, nelua_GCFinalizerCallback finalizer, void* userdata) {
  if(NELUA_UNLIKELY((size == 0))) {
    return (void*)NULL;
  }
  uintptr_t flags_4 = 0U;
  void* ptr = nelua_GeneralAllocator_alloc_1((&nelua_general_allocator), size, flags_4);
  nelua_GC_register((&nelua_gc), ptr, size, flags_4, finalizer, userdata);
  return ptr;
}
void* nelua_GCAllocator_alloc_3(nelua_GCAllocator_ptr self, uintptr_t size, uintptr_t flags, nelua_GCFinalizerCallback finalizer, void* userdata) {
  if(NELUA_UNLIKELY((size == 0))) {
    return (void*)NULL;
  }
  void* ptr = nelua_GeneralAllocator_alloc_1((&nelua_general_allocator), size, flags);
  nelua_GC_register((&nelua_gc), ptr, size, flags, finalizer, userdata);
  return ptr;
}
void* nelua_GCAllocator_alloc0_2(nelua_GCAllocator_ptr self, uintptr_t size, uintptr_t flags, nelua_GCFinalizerCallback finalizer, void* userdata) {
  if(NELUA_UNLIKELY((size == 0))) {
    return (void*)NULL;
  }
  void* ptr = nelua_GeneralAllocator_alloc0_2((&nelua_general_allocator), size, flags);
  nelua_GC_register((&nelua_gc), ptr, size, flags, finalizer, userdata);
  return ptr;
}
void nelua_GCAllocator_dealloc(nelua_GCAllocator_ptr self, void* ptr) {
  nelua_GC_unregister_1((&nelua_gc), ptr, true);
  nelua_GeneralAllocator_dealloc((&nelua_general_allocator), ptr);
}
void* nelua_GCAllocator_realloc(nelua_GCAllocator_ptr self, void* ptr, uintptr_t newsize, uintptr_t oldsize) {
  if(NELUA_UNLIKELY((ptr == (void*)NULL))) {
    return nelua_GCAllocator_alloc_1(self, newsize, NELUA_NIL, NELUA_NIL, NELUA_NIL);
  } else if(NELUA_UNLIKELY((newsize == 0))) {
    nelua_GCAllocator_dealloc(self, ptr);
    return (void*)NULL;
  } else if(NELUA_UNLIKELY((newsize == oldsize))) {
    return ptr;
  } else {
    void* newptr = nelua_GeneralAllocator_realloc((&nelua_general_allocator), ptr, newsize, oldsize);
    if((newptr != NULL)) {
      nelua_GC_reregister((&nelua_gc), ptr, newptr, newsize);
    }
    return newptr;
  }
}
nelua_span_uint8_ nelua_GCAllocator_spanalloc_2(nelua_GCAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags, nlniltype finalizer, nlniltype userdata) {
  uintptr_t flags_5 = 262144U;
  nelua_GCFinalizerCallback finalizer_2 = (nelua_GCFinalizerCallback)NULL;
  void* userdata_2 = (void*)NULL;
  if(NELUA_LIKELY((size > 0))) {
    nluint8_arr0_ptr data = ((nluint8_arr0_ptr)nelua_GCAllocator_alloc_3(self, (size * 1), flags_5, finalizer_2, userdata_2));
    if(NELUA_LIKELY((data != ((nluint8_arr0_ptr)NULL)))) {
      return (nelua_span_uint8_){.data = data, .size = size};
    }
  }
  return (nelua_span_uint8_){0};
}
nelua_span_Event_ nelua_GCAllocator_spanalloc_3(nelua_GCAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags, nlniltype finalizer, nlniltype userdata) {
  nelua_GCFinalizerCallback finalizer_3 = (nelua_GCFinalizerCallback)NULL;
  void* userdata_3 = (void*)NULL;
  if(NELUA_LIKELY((size > 0))) {
    engine_event_event_Event_arr0_ptr data = ((engine_event_event_Event_arr0_ptr)nelua_GCAllocator_alloc_2(self, (size * 24), NELUA_NIL, finalizer_3, userdata_3));
    if(NELUA_LIKELY((data != ((engine_event_event_Event_arr0_ptr)NULL)))) {
      return (nelua_span_Event_){.data = data, .size = size};
    }
  }
  return (nelua_span_Event_){0};
}
nelua_span_Widget_ nelua_GCAllocator_spanalloc_4(nelua_GCAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags, nlniltype finalizer, nlniltype userdata) {
  nelua_GCFinalizerCallback finalizer_4 = (nelua_GCFinalizerCallback)NULL;
  void* userdata_4 = (void*)NULL;
  if(NELUA_LIKELY((size > 0))) {
    engine_gui_gui_Widget_arr0_ptr data = ((engine_gui_gui_Widget_arr0_ptr)nelua_GCAllocator_alloc_2(self, (size * 136), NELUA_NIL, finalizer_4, userdata_4));
    if(NELUA_LIKELY((data != ((engine_gui_gui_Widget_arr0_ptr)NULL)))) {
      return (nelua_span_Widget_){.data = data, .size = size};
    }
  }
  return (nelua_span_Widget_){0};
}
nelua_span_UIWindow_ nelua_GCAllocator_spanalloc_6(nelua_GCAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags, nlniltype finalizer, nlniltype userdata) {
  nelua_GCFinalizerCallback finalizer_5 = (nelua_GCFinalizerCallback)NULL;
  void* userdata_5 = (void*)NULL;
  if(NELUA_LIKELY((size > 0))) {
    engine_gui_gui_UIWindow_arr0_ptr data = ((engine_gui_gui_UIWindow_arr0_ptr)nelua_GCAllocator_alloc_2(self, (size * 160), NELUA_NIL, finalizer_5, userdata_5));
    if(NELUA_LIKELY((data != ((engine_gui_gui_UIWindow_arr0_ptr)NULL)))) {
      return (nelua_span_UIWindow_){.data = data, .size = size};
    }
  }
  return (nelua_span_UIWindow_){0};
}
nelua_span_uint8_ nelua_GCAllocator_spanalloc0_1(nelua_GCAllocator_ptr self, nlniltype T, uintptr_t size, nlniltype flags, nlniltype finalizer, nlniltype userdata) {
  uintptr_t flags_6 = 262144U;
  nelua_GCFinalizerCallback finalizer_6 = (nelua_GCFinalizerCallback)NULL;
  void* userdata_6 = (void*)NULL;
  if(NELUA_LIKELY((size > 0))) {
    nluint8_arr0_ptr data = ((nluint8_arr0_ptr)nelua_GCAllocator_alloc0_2(self, (size * 1), flags_6, finalizer_6, userdata_6));
    if(NELUA_LIKELY((data != ((nluint8_arr0_ptr)NULL)))) {
      return (nelua_span_uint8_){.data = data, .size = size};
    }
  }
  return (nelua_span_uint8_){0};
}
void* nelua_GCAllocator_xalloc_1(nelua_GCAllocator_ptr self, uintptr_t size, nlniltype flags) {
  void* p = nelua_GCAllocator_alloc_1(self, size, NELUA_NIL, NELUA_NIL, NELUA_NIL);
  if(NELUA_UNLIKELY(((p == (void*)NULL) && (size > 0)))) {
    nelua_panic_string(((nlstring){(uint8_t*)"out of memory", 13}));
  }
  return p;
}
void* nelua_GCAllocator_realloc0(nelua_GCAllocator_ptr self, void* p, uintptr_t newsize, uintptr_t oldsize) {
  p = nelua_GCAllocator_realloc(self, p, newsize, oldsize);
  if(NELUA_LIKELY(((newsize > oldsize) && (p != (void*)NULL)))) {
    nelua_memory_zero((void*)(&((nluint8_arr0_ptr)p)[oldsize]), (newsize - oldsize));
  }
  return p;
}
void nelua_GCAllocator_spandealloc_1(nelua_GCAllocator_ptr self, nelua_span_uint8_ s) {
  if(NELUA_UNLIKELY((s.size == 0))) {
    return;
  }
  nelua_GCAllocator_dealloc(self, (void*)s.data);
}
nelua_span_uint8_ nelua_GCAllocator_spanrealloc_1(nelua_GCAllocator_ptr self, nelua_span_uint8_ s, uintptr_t size) {
  if(NELUA_UNLIKELY(((s.size == 0) && (size > 0)))) {
    s = nelua_GCAllocator_spanalloc_2(self, NELUA_NIL, size, NELUA_NIL, NELUA_NIL, NELUA_NIL);
    return s;
  }
  nluint8_arr0_ptr p = ((nluint8_arr0_ptr)nelua_GCAllocator_realloc(self, (void*)s.data, (size * 1), (s.size * 1)));
  if(NELUA_UNLIKELY(((size > 0) && (p == ((nluint8_arr0_ptr)NULL))))) {
    return s;
  }
  s.data = p;
  s.size = size;
  return s;
}
nelua_span_Event_ nelua_GCAllocator_spanrealloc_3(nelua_GCAllocator_ptr self, nelua_span_Event_ s, uintptr_t size) {
  if(NELUA_UNLIKELY(((s.size == 0) && (size > 0)))) {
    s = nelua_GCAllocator_spanalloc_3(self, NELUA_NIL, size, NELUA_NIL, NELUA_NIL, NELUA_NIL);
    return s;
  }
  engine_event_event_Event_arr0_ptr p = ((engine_event_event_Event_arr0_ptr)nelua_GCAllocator_realloc(self, (void*)s.data, (size * 24), (s.size * 24)));
  if(NELUA_UNLIKELY(((size > 0) && (p == ((engine_event_event_Event_arr0_ptr)NULL))))) {
    return s;
  }
  s.data = p;
  s.size = size;
  return s;
}
nelua_span_Widget_ nelua_GCAllocator_spanrealloc_4(nelua_GCAllocator_ptr self, nelua_span_Widget_ s, uintptr_t size) {
  if(NELUA_UNLIKELY(((s.size == 0) && (size > 0)))) {
    s = nelua_GCAllocator_spanalloc_4(self, NELUA_NIL, size, NELUA_NIL, NELUA_NIL, NELUA_NIL);
    return s;
  }
  engine_gui_gui_Widget_arr0_ptr p = ((engine_gui_gui_Widget_arr0_ptr)nelua_GCAllocator_realloc(self, (void*)s.data, (size * 136), (s.size * 136)));
  if(NELUA_UNLIKELY(((size > 0) && (p == ((engine_gui_gui_Widget_arr0_ptr)NULL))))) {
    return s;
  }
  s.data = p;
  s.size = size;
  return s;
}
nelua_span_UIWindow_ nelua_GCAllocator_spanrealloc_6(nelua_GCAllocator_ptr self, nelua_span_UIWindow_ s, uintptr_t size) {
  if(NELUA_UNLIKELY(((s.size == 0) && (size > 0)))) {
    s = nelua_GCAllocator_spanalloc_6(self, NELUA_NIL, size, NELUA_NIL, NELUA_NIL, NELUA_NIL);
    return s;
  }
  engine_gui_gui_UIWindow_arr0_ptr p = ((engine_gui_gui_UIWindow_arr0_ptr)nelua_GCAllocator_realloc(self, (void*)s.data, (size * 160), (s.size * 160)));
  if(NELUA_UNLIKELY(((size > 0) && (p == ((engine_gui_gui_UIWindow_arr0_ptr)NULL))))) {
    return s;
  }
  s.data = p;
  s.size = size;
  return s;
}
nelua_span_uint8_ nelua_GCAllocator_xspanrealloc_1(nelua_GCAllocator_ptr self, nelua_span_uint8_ s, uintptr_t size) {
  s = nelua_GCAllocator_spanrealloc_1(self, s, size);
  if(NELUA_UNLIKELY((s.size != size))) {
    nelua_panic_string(((nlstring){(uint8_t*)"out of memory", 13}));
  }
  return s;
}
nelua_span_Event_ nelua_GCAllocator_xspanrealloc_3(nelua_GCAllocator_ptr self, nelua_span_Event_ s, uintptr_t size) {
  s = nelua_GCAllocator_spanrealloc_3(self, s, size);
  if(NELUA_UNLIKELY((s.size != size))) {
    nelua_panic_string(((nlstring){(uint8_t*)"out of memory", 13}));
  }
  return s;
}
nelua_span_Widget_ nelua_GCAllocator_xspanrealloc_4(nelua_GCAllocator_ptr self, nelua_span_Widget_ s, uintptr_t size) {
  s = nelua_GCAllocator_spanrealloc_4(self, s, size);
  if(NELUA_UNLIKELY((s.size != size))) {
    nelua_panic_string(((nlstring){(uint8_t*)"out of memory", 13}));
  }
  return s;
}
nelua_span_UIWindow_ nelua_GCAllocator_xspanrealloc_6(nelua_GCAllocator_ptr self, nelua_span_UIWindow_ s, uintptr_t size) {
  s = nelua_GCAllocator_spanrealloc_6(self, s, size);
  if(NELUA_UNLIKELY((s.size != size))) {
    nelua_panic_string(((nlstring){(uint8_t*)"out of memory", 13}));
  }
  return s;
}
nelua_span_uint8_ nelua_GCAllocator_spanrealloc0_1(nelua_GCAllocator_ptr self, nelua_span_uint8_ s, uintptr_t size) {
  if(NELUA_UNLIKELY(((s.size == 0) && (size > 0)))) {
    s = nelua_GCAllocator_spanalloc0_1(self, NELUA_NIL, size, NELUA_NIL, NELUA_NIL, NELUA_NIL);
    return s;
  }
  nluint8_arr0_ptr p = ((nluint8_arr0_ptr)nelua_GCAllocator_realloc0(self, (void*)s.data, (size * 1), (s.size * 1)));
  if(NELUA_UNLIKELY(((size > 0) && (p == ((nluint8_arr0_ptr)NULL))))) {
    return s;
  }
  s.data = p;
  s.size = size;
  return s;
}
uintptr_t nelua_assert_bounds_nlusize(uintptr_t index, uintptr_t len) {
  if(NELUA_UNLIKELY((uintptr_t)index >= len)) {
    nelua_panic_cstring("array index: position out of bounds");
  }
  return index;
}
nlstring nelua_strconv_1_int2str_1(nluint8_arr48_ptr buf, intptr_t x, nlniltype base) {
  uintptr_t pos = 47U;
  buf->v[nelua_assert_bounds_nlusize(pos, 48)] = 0U;
  pos = (pos - 1);
  bool neg = (x < 0);
  if((x == 0)) {
    buf->v[nelua_assert_bounds_nlusize(pos, 48)] = 48U;
    pos = (pos - 1);
  } else {
    while((x != 0)) {
      intptr_t quot = (x / 10);
      intptr_t rema = (x - (quot * 10));
      if((rema < 0)) {
        rema = (-rema);
      }
      x = quot;
      buf->v[nelua_assert_bounds_nlusize(pos, 48)] = (uint8_t)(rema + 48);
      pos = (pos - 1);
    }
  }
  if(neg) {
    buf->v[nelua_assert_bounds_nlusize(pos, 48)] = 45U;
    pos = (pos - 1);
  }
  return (nlstring){.data = ((nluint8_arr0_ptr)(&buf->v[nelua_assert_bounds_nlusize((pos + 1), 48)])), .size = ((48 - pos) - 2)};
}
void nelua_stringbuilderT_destroy(nelua_stringbuilderT_ptr self) {
  nelua_GCAllocator_spandealloc_1((&self->allocator), self->data);
  self->data = (nelua_span_uint8_){0};
  self->size = 0U;
}
bool nelua_stringbuilderT_grow(nelua_stringbuilderT_ptr self, uintptr_t newsize) {
  uintptr_t needed = (newsize + 1);
  uintptr_t cap = self->data.size;
  if((needed <= cap)) {
    return true;
  }
  if((cap == 0)) {
    cap = 16U;
  }
  while((cap < needed)) {
    cap = (cap * 2);
    if((cap <= 16U)) {
      return false;
    }
  }
  self->data = nelua_GCAllocator_spanrealloc0_1((&self->allocator), self->data, cap);
  if((self->data.size != cap)) {
    self->data = nelua_GCAllocator_spanrealloc0_1((&self->allocator), self->data, needed);
  }
  return (needed <= self->data.size);
}
nelua_span_uint8_ nelua_stringbuilderT_prepare(nelua_stringbuilderT_ptr self, uintptr_t n) {
  if((!nelua_stringbuilderT_grow(self, (self->size + n)))) {
    return (nelua_span_uint8_){0};
  }
  return (nelua_span_uint8_){.data = ((nluint8_arr0_ptr)(&(*(uint8_t*)nelua_assert_deref(nelua_span_uint8____atindex(self->data, self->size))))), .size = ((self->data.size - self->size) - 1)};
}
void nelua_assert_line_31(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/stringbuilder.nelua:150:19: runtime error: ", 62, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n    check(newsize <= self.data.size, 'not enough space in string buffer')\n                  ^~~~~~~~~~~~~~~~~\n", 111, true);
    nelua_abort();
  }
}
void nelua_stringbuilderT_commit(nelua_stringbuilderT_ptr self, uintptr_t n) {
  uintptr_t newsize = (self->size + n);
  nelua_assert_line_31((newsize <= self->data.size), ((nlstring){(uint8_t*)"not enough space in string buffer", 33}));
  self->size = newsize;
}
nlstring nelua_stringbuilderT_promote(nelua_stringbuilderT_ptr self) {
  if(NELUA_UNLIKELY((self->size == 0))) {
    nelua_stringbuilderT_destroy(self);
    return (nlstring){0};
  }
  uintptr_t size = self->size;
  nelua_span_uint8_ data = nelua_GCAllocator_xspanrealloc_1((&self->allocator), self->data, (size + 1));
  (*(uint8_t*)nelua_assert_deref(nelua_span_uint8____atindex(data, size))) = 0U;
  self->data = (nelua_span_uint8_){0};
  self->size = 0U;
  return (nlstring){.data = data.data, .size = size};
}
void nelua_assert_line_32(bool cond, nlstring msg) {
  if(NELUA_UNLIKELY(!cond)) {
    nelua_write_stderr("/usr/lib/nelua/lib/string.nelua:35:14: runtime error: ", 54, false);
    nelua_write_stderr((const char*)msg.data, msg.size, false);
    nelua_write_stderr("\n  check(size > 0, 'attempt to create an empty string')\n             ^~~\n", 73, true);
    nelua_abort();
  }
}
nlstring nelua_nlstring_create(uintptr_t size) {
  nelua_assert_line_32((size > 0), ((nlstring){(uint8_t*)"attempt to create an empty string", 33}));
  nlstring s = (nlstring){.data = ((nluint8_arr0_ptr)nelua_GCAllocator_xalloc_1((&nelua_gc_allocator), (size + 1), NELUA_NIL)), .size = size};
  s.data[size] = 0U;
  return s;
}
nlstring nelua_nlstring_copy(nlstring s) {
  nlstring clone = (nlstring){0};
  if(NELUA_UNLIKELY((s.size == 0))) {
    return clone;
  }
  clone.data = ((nluint8_arr0_ptr)nelua_GCAllocator_xalloc_1((&nelua_gc_allocator), (s.size + 1), NELUA_NIL));
  nelua_memory_copy((void*)clone.data, (void*)s.data, s.size);
  clone.data[s.size] = 0U;
  clone.size = s.size;
  return clone;
}
nlstring nelua_nlstring___concat_1(nlstring a, nlstring b) {
  if((a.size == 0)) {
    return nelua_nlstring_copy(b);
  } else if((b.size == 0)) {
    return nelua_nlstring_copy(a);
  }
  nlstring s = nelua_nlstring_create((a.size + b.size));
  nelua_memory_copy((void*)s.data, (void*)a.data, a.size);
  nelua_memory_copy((void*)(&s.data[a.size]), (void*)b.data, b.size);
  return s;
}
bool nelua_nlstring___eq(nlstring a, nlstring b) {
  return ((a.size == b.size) && (((a.data == b.data) || (a.size == 0)) || nelua_memory_equals((void*)a.data, (void*)b.data, a.size)));
}
nlstring nelua_tostring_1(int x) {
  nluint8_arr48 buf;
  nlstring s = nelua_strconv_1_int2str_1((&buf), (intptr_t)x, NELUA_NIL);
  return nelua_nlstring_copy(s);
}
char* nelua_assert_string2cstring(nlstring s) {
  if(s.size == 0) {
    return (char*)"";
  }
  if(NELUA_UNLIKELY(s.data[s.size]) != 0) {
    nelua_panic_cstring("attempt to convert a non null terminated string to cstring");
  }
  return (char*)s.data;
}
nlstring nelua_cstring2string(const char* s) {
  if(s == NULL) {
    return (nlstring){0};
  }
  uintptr_t size = strlen(s);
  if(size == 0) {
    return (nlstring){0};
  }
  return (nlstring){(uint8_t*)s, size};
}
nlmulret_nlstring_nlstring_nlint64 engine_fileystem_filesystem_fs_readfile(nlstring path) {
  int fd = open(nelua_assert_string2cstring(path), O_RDONLY, 0U);
  if((fd < 0)) {
    return (nlmulret_nlstring_nlstring_nlint64){(nlstring){0}, nelua_cstring2string(strerror(errno)), (int64_t)errno};
  }
  nelua_stringbuilderT sb = (nelua_stringbuilderT){0};
  {
    bool _repeat_stop;
    do {
      nelua_span_uint8_ p = nelua_stringbuilderT_prepare((&sb), 4096U);
      if(nelua_span_uint8__empty(p)) {
        nelua_stringbuilderT_destroy((&sb));
        nlmulret_nlstring_nlstring_nlint64 _mulret_1;
        _mulret_1.r1 = (nlstring){0};
        _mulret_1.r2 = ((nlstring){(uint8_t*)"out of buffer memory", 20});
        _mulret_1.r3 = -1;
        { /* defer */
          close(fd);
        }
        return _mulret_1;
      }
      intptr_t nr = (intptr_t)read(fd, (void*)p.data, 4096U);
      if((nr < 0)) {
        nelua_stringbuilderT_destroy((&sb));
        nlmulret_nlstring_nlstring_nlint64 _mulret_2;
        _mulret_2.r1 = (nlstring){0};
        _mulret_2.r2 = nelua_cstring2string(strerror(errno));
        _mulret_2.r3 = (int64_t)errno;
        { /* defer */
          close(fd);
        }
        return _mulret_2;
      }
      nelua_stringbuilderT_commit((&sb), (uintptr_t)nr);
      _repeat_stop = (nr < 4096);
    } while(!_repeat_stop);
  }
  nlmulret_nlstring_nlstring_nlint64 _mulret_3;
  _mulret_3.r1 = nelua_stringbuilderT_promote((&sb));
  _mulret_3.r2 = (nlstring){0};
  _mulret_3.r3 = 0;
  { /* defer */
    close(fd);
  }
  return _mulret_3;
}
void nelua_print_1(nlstring a1, nlstring a2, nlstring a3) {
  if(a1.size > 0) {
    fwrite(a1.data, 1, a1.size, stdout);
  }
  fputs("	", stdout);
  if(a2.size > 0) {
    fwrite(a2.data, 1, a2.size, stdout);
  }
  fputs("	", stdout);
  if(a3.size > 0) {
    fwrite(a3.data, 1, a3.size, stdout);
  }
  fputs("\n", stdout);
  fflush(stdout);
}
void nelua_print_2(nlstring a1, nlstring a2) {
  if(a1.size > 0) {
    fwrite(a1.data, 1, a1.size, stdout);
  }
  fputs("	", stdout);
  if(a2.size > 0) {
    fwrite(a2.data, 1, a2.size, stdout);
  }
  fputs("\n", stdout);
  fflush(stdout);
}
void nelua_print_3(nlstring a1) {
  if(a1.size > 0) {
    fwrite(a1.data, 1, a1.size, stdout);
  }
  fputs("\n", stdout);
  fflush(stdout);
}
void engine_information_handler_information_handler_InformationHandlerClass_RaiseError(engine_information_handler_information_handler_InformationHandlerClass_ptr self, int severity, nlstring reason) {
  switch(severity) {
    case 1: {
      nelua_print_1(((nlstring){(uint8_t*)"\n\033[31mERROR", 11}), ((nlstring){(uint8_t*)"Simple clean exit, something went wrong. The reason is as follows: ", 67}), reason);
      self->isHaulted = true;
      break;
    }
    case 2: {
      nelua_print_1(((nlstring){(uint8_t*)"\n\033[31mERROR", 11}), ((nlstring){(uint8_t*)"Something went pretty wrong. The reason is as follows: ", 55}), reason);
      self->isHaulted = true;
      break;
    }
    case 3: {
      nelua_print_1(((nlstring){(uint8_t*)"\n\033[31mERROR", 11}), ((nlstring){(uint8_t*)nelua_strlit_1, 96}), reason);
      self->isHaulted = true;
      break;
    }
    default: {
      nelua_print_2(((nlstring){(uint8_t*)"\n\033[31mERROR", 11}), ((nlstring){(uint8_t*)"That's not an understood severity code!", 39}));
      self->isHaulted = true;
      break;
    }
  }
  nelua_print_3(((nlstring){(uint8_t*)"\n\033[37mDefault output:", 21}));
}
void engine_information_handler_information_handler_InformationHandlerClass_Log(engine_information_handler_information_handler_InformationHandlerClass_ptr self, nlstring reason) {
  nelua_print_1(((nlstring){(uint8_t*)"\n\033[32mLOG", 9}), reason, ((nlstring){(uint8_t*)"\n\033[37m", 6}));
}
void engine_information_handler_information_handler_InformationHandlerClass_Warn(engine_information_handler_information_handler_InformationHandlerClass_ptr self, nlstring reason) {
  nelua_print_1(((nlstring){(uint8_t*)"\n\033[93mWARN", 10}), reason, ((nlstring){(uint8_t*)"\n\033[37m", 6}));
}
bool engine_utilities__UtilityClass_IsInsideQuad(engine_utilities__UtilityClass_ptr self, Vector2 point, Vector2 tl, Vector2 br) {
  if(((((point.x >= tl.x) && (point.x <= br.x)) && (point.y >= tl.y)) && (point.y <= br.y))) {
    return true;
  }
  return false;
}
int nelua_assert_narrow_nlfloat32_nlcint(float x) {
  if(NELUA_UNLIKELY((int)(x) != x)) {
    nelua_panic_cstring("narrow casting from float32 to cint failed");
  }
  return (int)x;
}
void engine_utilities__UtilityClass_DrawBoxWithOutline(engine_utilities__UtilityClass_ptr self, Vector2 pos, Vector2 size, int pad, Color bgColor, Color borderColor) {
  DrawRectangle(nelua_assert_narrow_nlfloat32_nlcint(pos.x), nelua_assert_narrow_nlfloat32_nlcint(pos.y), nelua_assert_narrow_nlfloat32_nlcint(size.x), nelua_assert_narrow_nlfloat32_nlcint(size.y), borderColor);
  DrawRectangle(nelua_assert_narrow_nlfloat32_nlcint((pos.x + pad)), nelua_assert_narrow_nlfloat32_nlcint((pos.y + pad)), nelua_assert_narrow_nlfloat32_nlcint((size.x - (pad * 2))), nelua_assert_narrow_nlfloat32_nlcint((size.y - (pad * 2))), bgColor);
}
void engine_mouse_mouse_MouseClass_Update(engine_mouse_mouse_MouseClass_ptr self) {
  self->x = GetMouseX();
  self->y = GetMouseY();
  self->LMBDown = IsMouseButtonDown(0);
  self->MMBDown = IsMouseButtonDown(1);
  self->RMBDown = IsMouseButtonDown(0);
  self->LMBPressed = IsMouseButtonPressed(0);
  self->RMBPressed = IsMouseButtonPressed(1);
  self->LMBReleased = IsMouseButtonReleased(0);
  self->scrollWheelMove = nelua_assert_narrow_nlfloat32_nlcint(GetMouseWheelMove());
}
int64_t nelua_assert_narrow_nlusize_nlint64(uintptr_t x) {
  if(NELUA_UNLIKELY(x > 0x7fffffffffffffffULL)) {
    nelua_panic_cstring("narrow casting from usize to int64 failed");
  }
  return (int64_t)x;
}
void engine_event_manager_event_manager_EventManagerRecord_RevealEvents(engine_event_manager_event_manager_EventManagerRecord_ptr self) {
  {
    nlmulret_function_5gquHoPNaDqkV7fJH_nelua_vector_Event__ptr_nlint64 _asgnret_1 = nelua_ipairs_1((&self->Events));
    function_5gquHoPNaDqkV7fJH __fornext = _asgnret_1.r1;
    nelua_vector_Event__ptr __forstate = _asgnret_1.r2;
    int64_t __fornextit = _asgnret_1.r3;
    while(true) {
      nlmulret_nlboolean_nlint64_engine_event_event_Event _asgnret_2 = __fornext(__forstate, __fornextit);
      bool __forcont = _asgnret_2.r1;
      uintptr_t i = nelua_assert_narrow_nlint64_nlusize(_asgnret_2.r2);
      engine_event_event_Event event = _asgnret_2.r3;
      if((!__forcont)) {
        break;
      }
      __fornextit = nelua_assert_narrow_nlusize_nlint64(i);
      {
        engine_information_handler_information_handler_InformationHandlerClass_Log((&engine_information_handler_information_handler_InformationHandler), event.name);
      }
    }
  }
}
void engine_event_manager_event_manager_EventManagerRecord_AddEvent(engine_event_manager_event_manager_EventManagerRecord_ptr self, nlstring uEventName) {
  nelua_vector_Event__push((&self->Events), (engine_event_event_Event){uEventName, false});
}
void engine_event_manager_event_manager_EventManagerRecord_FireEvent(engine_event_manager_event_manager_EventManagerRecord_ptr self, nlstring uEventName) {
  {
    nlmulret_function_DMiQwk1wKUehs9jb_nelua_vector_Event__ptr_nlint64 _asgnret_1 = nelua_mipairs_1((&self->Events));
    function_DMiQwk1wKUehs9jb __fornext = _asgnret_1.r1;
    nelua_vector_Event__ptr __forstate = _asgnret_1.r2;
    int64_t __fornextit = _asgnret_1.r3;
    while(true) {
      nlmulret_nlboolean_nlint64_engine_event_event_Event_ptr _asgnret_2 = __fornext(__forstate, __fornextit);
      bool __forcont = _asgnret_2.r1;
      uintptr_t i = nelua_assert_narrow_nlint64_nlusize(_asgnret_2.r2);
      engine_event_event_Event_ptr event = _asgnret_2.r3;
      if((!__forcont)) {
        break;
      }
      __fornextit = nelua_assert_narrow_nlusize_nlint64(i);
      {
        if(nelua_nlstring___eq(event->name, uEventName)) {
          event->fired = true;
        }
      }
    }
  }
}
void engine_event_manager_event_manager_EventManagerRecord_Cleanup(engine_event_manager_event_manager_EventManagerRecord_ptr self, nlstring uEventName) {
  {
    nlmulret_function_DMiQwk1wKUehs9jb_nelua_vector_Event__ptr_nlint64 _asgnret_1 = nelua_mipairs_1((&self->Events));
    function_DMiQwk1wKUehs9jb __fornext = _asgnret_1.r1;
    nelua_vector_Event__ptr __forstate = _asgnret_1.r2;
    int64_t __fornextit = _asgnret_1.r3;
    while(true) {
      nlmulret_nlboolean_nlint64_engine_event_event_Event_ptr _asgnret_2 = __fornext(__forstate, __fornextit);
      bool __forcont = _asgnret_2.r1;
      uintptr_t i = nelua_assert_narrow_nlint64_nlusize(_asgnret_2.r2);
      engine_event_event_Event_ptr event = _asgnret_2.r3;
      if((!__forcont)) {
        break;
      }
      __fornextit = nelua_assert_narrow_nlusize_nlint64(i);
      {
        if(nelua_nlstring___eq(event->name, uEventName)) {
          event->fired = false;
        }
      }
    }
  }
}
engine_event_event_Event engine_event_manager_event_manager_EventManagerRecord_GetEvent(engine_event_manager_event_manager_EventManagerRecord_ptr self, nlstring uEventName) {
  {
    nlmulret_function_5gquHoPNaDqkV7fJH_nelua_vector_Event__ptr_nlint64 _asgnret_1 = nelua_ipairs_1((&self->Events));
    function_5gquHoPNaDqkV7fJH __fornext = _asgnret_1.r1;
    nelua_vector_Event__ptr __forstate = _asgnret_1.r2;
    int64_t __fornextit = _asgnret_1.r3;
    while(true) {
      nlmulret_nlboolean_nlint64_engine_event_event_Event _asgnret_2 = __fornext(__forstate, __fornextit);
      bool __forcont = _asgnret_2.r1;
      uintptr_t i = nelua_assert_narrow_nlint64_nlusize(_asgnret_2.r2);
      engine_event_event_Event event = _asgnret_2.r3;
      if((!__forcont)) {
        break;
      }
      __fornextit = nelua_assert_narrow_nlusize_nlint64(i);
      {
        if(nelua_nlstring___eq(event.name, uEventName)) {
          return event;
        }
      }
    }
  }
  return (engine_event_event_Event){0};
}
void engine_gui_gui_Widget_Init(engine_gui_gui_Widget_ptr self) {
  self->tl.x = self->position.x;
  self->tl.y = self->position.y;
  self->br.x = self->size.x;
  self->br.y = self->size.y;
}
void engine_gui_gui_Widget_UpdateVW(engine_gui_gui_Widget_ptr self) {
  self->tlW.x = (self->tl.x + self->windowPosition.x);
  self->tlW.y = (self->tl.y + self->windowPosition.y);
  self->brW.x = ((self->br.x + self->tl.x) + self->windowPosition.x);
  self->brW.y = ((self->br.y + self->tl.y) + self->windowPosition.y);
}
void engine_gui_gui_Widget_Draw(engine_gui_gui_Widget_ptr self) {
  if(nelua_nlstring___eq(self->widgetType, ((nlstring){(uint8_t*)"Button", 6}))) {
    if((self->isShown || self->alwaysDrawn)) {
      if(self->isDown) {
        engine_utilities__UtilityClass_DrawBoxWithOutline((&engine_utilities__Utility), (Vector2){(self->position.x + self->windowPosition.x), (self->position.y + self->windowPosition.y)}, (Vector2){self->size.x, self->size.y}, self->borderSize, (Color){(self->bgColor.r + 20), (self->bgColor.g + 20), (self->bgColor.b + 20), self->bgColor.a}, self->borderColor);
      } else if(self->isHighlighted) {
        engine_utilities__UtilityClass_DrawBoxWithOutline((&engine_utilities__Utility), (Vector2){(self->position.x + self->windowPosition.x), (self->position.y + self->windowPosition.y)}, (Vector2){self->size.x, self->size.y}, self->borderSize, (Color){(self->bgColor.r + 10), (self->bgColor.g + 10), (self->bgColor.b + 10), self->bgColor.a}, self->borderColor);
      } else {
        engine_utilities__UtilityClass_DrawBoxWithOutline((&engine_utilities__Utility), (Vector2){(self->position.x + self->windowPosition.x), (self->position.y + self->windowPosition.y)}, (Vector2){self->size.x, self->size.y}, self->borderSize, self->bgColor, self->borderColor);
      }
      DrawText(nelua_assert_string2cstring(self->widgetText), nelua_assert_narrow_nlfloat32_nlcint((self->tlW.x + (self->borderSize * 2))), nelua_assert_narrow_nlfloat32_nlcint((self->tlW.y + (self->borderSize * 2))), self->fontSize, self->fgColor);
    }
  } else if(nelua_nlstring___eq(self->widgetType, ((nlstring){(uint8_t*)"Selectable", 10}))) {
    if((self->isShown || self->alwaysDrawn)) {
      if(self->isDown) {
        engine_utilities__UtilityClass_DrawBoxWithOutline((&engine_utilities__Utility), (Vector2){(self->position.x + self->windowPosition.x), (self->position.y + self->windowPosition.y)}, (Vector2){self->size.x, self->size.y}, self->borderSize, self->bgColor, (Color){(self->borderColor.r + 10), (self->borderColor.g + 10), (self->borderColor.b + 10), self->borderColor.a});
      } else {
        engine_utilities__UtilityClass_DrawBoxWithOutline((&engine_utilities__Utility), (Vector2){(self->position.x + self->windowPosition.x), (self->position.y + self->windowPosition.y)}, (Vector2){self->size.x, self->size.y}, self->borderSize, self->bgColor, self->borderColor);
      }
      DrawText(nelua_assert_string2cstring(self->widgetText), nelua_assert_narrow_nlfloat32_nlcint((self->tlW.x + (self->borderSize * 2))), nelua_assert_narrow_nlfloat32_nlcint((self->tlW.y + (self->borderSize * 2))), self->fontSize, self->fgColor);
    }
  }
}
void engine_gui_gui_Widget_Update(engine_gui_gui_Widget_ptr self) {
  if(self->autoSize) {
    self->size.x = (float)(MeasureText(nelua_assert_string2cstring(self->widgetText), self->fontSize) + (self->borderSize * 4));
    self->size.y = (float)(self->fontSize * 2);
  }
  if((nelua_nlstring___eq(self->widgetType, ((nlstring){(uint8_t*)"Button", 6})) || nelua_nlstring___eq(self->widgetType, ((nlstring){(uint8_t*)"Selectable", 10})))) {
    if(engine_utilities__UtilityClass_IsInsideQuad((&engine_utilities__Utility), (Vector2){(float)engine_mouse_mouse_Mouse.x, (float)engine_mouse_mouse_Mouse.y}, self->tlW, self->brW)) {
      self->isHighlighted = true;
    } else {
      self->isHighlighted = false;
    }
  } else if(nelua_nlstring___eq(self->widgetType, ((nlstring){(uint8_t*)"Selectable", 10}))) {
  } else {
    engine_information_handler_information_handler_InformationHandlerClass_Warn((&engine_information_handler_information_handler_InformationHandler), ((nlstring){(uint8_t*)"Unaware of the widget type", 26}));
  }
  if(self->spaceOccupied) {
    if(nelua_nlstring___eq(self->widgetType, ((nlstring){(uint8_t*)"Button", 6}))) {
      if((self->isHighlighted && engine_mouse_mouse_Mouse.LMBPressed)) {
        engine_event_manager_event_manager_EventManagerRecord_FireEvent((&engine_event_manager_event_manager_EventManager), self->widgetName);
      }
      if((self->isHighlighted && engine_mouse_mouse_Mouse.LMBDown)) {
        self->isDown = true;
      } else {
        self->isDown = false;
      }
    } else if(nelua_nlstring___eq(self->widgetType, ((nlstring){(uint8_t*)"Selectable", 10}))) {
      if((self->isHighlighted && engine_mouse_mouse_Mouse.LMBPressed)) {
        engine_event_manager_event_manager_EventManagerRecord_FireEvent((&engine_event_manager_event_manager_EventManager), self->widgetName);
      }
      if((self->isHighlighted && engine_mouse_mouse_Mouse.LMBDown)) {
        self->isDown = true;
      } else {
        self->isDown = false;
      }
    } else {
      engine_information_handler_information_handler_InformationHandlerClass_Warn((&engine_information_handler_information_handler_InformationHandler), ((nlstring){(uint8_t*)"Unaware of the widget type", 26}));
    }
  }
  engine_gui_gui_Widget_Draw(self);
}
void engine_gui_gui_UIWindow_Init(engine_gui_gui_UIWindow_ptr self) {
  self->originalPosition = self->pos;
}
void engine_gui_gui_UIWindow_Update(engine_gui_gui_UIWindow_ptr self) {
  if(engine_event_manager_event_manager_EventManagerRecord_GetEvent((&engine_event_manager_event_manager_EventManager), nelua_nlstring___concat_1(self->windowName, ((nlstring){(uint8_t*)"ResetDebounce", 13}))).fired) {
    self->grabDebounce = 0;
  } else {
    self->grabDebounce = (self->grabDebounce + 1);
  }
  if(engine_mouse_mouse_Mouse.LMBPressed) {
    if(((engine_utilities__UtilityClass_IsInsideQuad((&engine_utilities__Utility), (Vector2){(float)engine_mouse_mouse_Mouse.x, (float)engine_mouse_mouse_Mouse.y}, (Vector2){self->pos.x, self->pos.y}, (Vector2){(self->pos.x + self->size.x), (self->pos.y + self->menuBarSize)}) && (!engine_mouse_mouse_Mouse.insideUIElement)) && (self->grabDebounce >= 4))) {
      self->mouseOffset = (Vector2){(self->pos.x - engine_mouse_mouse_Mouse.x), (self->pos.y - engine_mouse_mouse_Mouse.y)};
      engine_mouse_mouse_Mouse.isGrabbing = true;
      engine_mouse_mouse_Mouse.windowGrabbed = self->windowName;
    }
  } else if(engine_mouse_mouse_Mouse.LMBReleased) {
    engine_mouse_mouse_Mouse.isGrabbing = false;
  }
  if(((engine_mouse_mouse_Mouse.isGrabbing && nelua_nlstring___eq(engine_mouse_mouse_Mouse.windowGrabbed, self->windowName)) && (!engine_mouse_mouse_Mouse.insideUIElement))) {
    self->pos = (Vector2){(engine_mouse_mouse_Mouse.x + self->mouseOffset.x), (engine_mouse_mouse_Mouse.y + self->mouseOffset.y)};
  }
}
void engine_gui_gui_UIWindow_Draw(engine_gui_gui_UIWindow_ptr self) {
  if(self->isShown) {
    if((self->borderSize > 0)) {
      DrawRectangle(nelua_assert_narrow_nlfloat32_nlcint(self->pos.x), nelua_assert_narrow_nlfloat32_nlcint(self->pos.y), nelua_assert_narrow_nlfloat32_nlcint(self->size.x), nelua_assert_narrow_nlfloat32_nlcint(self->size.y), self->borderColor);
      DrawRectangle(nelua_assert_narrow_nlfloat32_nlcint((self->pos.x + self->borderSize)), nelua_assert_narrow_nlfloat32_nlcint((self->pos.y + self->borderSize)), nelua_assert_narrow_nlfloat32_nlcint((self->size.x - (self->borderSize * 2))), nelua_assert_narrow_nlfloat32_nlcint((self->size.y - (self->borderSize * 2))), self->bgColor);
    } else {
      DrawRectangle(nelua_assert_narrow_nlfloat32_nlcint(self->pos.x), nelua_assert_narrow_nlfloat32_nlcint(self->pos.y), nelua_assert_narrow_nlfloat32_nlcint(self->size.x), nelua_assert_narrow_nlfloat32_nlcint(self->size.y), self->bgColor);
    }
  }
  if(self->menuBarEnabled) {
    DrawRectangle(nelua_assert_narrow_nlfloat32_nlcint(self->pos.x), nelua_assert_narrow_nlfloat32_nlcint(self->pos.y), nelua_assert_narrow_nlfloat32_nlcint(self->size.x), self->menuBarSize, self->borderColor);
    DrawRectangle(nelua_assert_narrow_nlfloat32_nlcint((self->pos.x + self->borderSize)), nelua_assert_narrow_nlfloat32_nlcint((self->pos.y + self->borderSize)), nelua_assert_narrow_nlfloat32_nlcint((self->size.x - (self->borderSize * 2))), (self->menuBarSize - (self->borderSize * 2)), self->bgColor);
    DrawText(nelua_assert_string2cstring(self->menuBarText), nelua_assert_narrow_nlfloat32_nlcint(((self->pos.x + self->borderSize) + self->menuTextPadding)), nelua_assert_narrow_nlfloat32_nlcint(((self->pos.y + self->borderSize) + self->menuTextPadding)), self->menuFontSize, self->fgColor);
  }
}
uintptr_t nelua_assert_narrow_nlisize_nlusize(intptr_t x) {
  if(NELUA_UNLIKELY(x < 0)) {
    nelua_panic_cstring("narrow casting from isize to usize failed");
  }
  return (uintptr_t)x;
}
void engine_uimanager_uimanager_UIManagerClass_AddWidget(engine_uimanager_uimanager_UIManagerClass_ptr self, nlstring uWindowName, nlstring uWidgetName, nlstring uWidgetType, nlstring uWidgetText, int uWidgetFontSize, Vector2 uWidgetPosition, Vector2 uWidgetSize, bool uWidgetAlwaysDrawn, bool uAutoSize) {
  {
    nlmulret_function_Po1535aji1YbmWk6_nelua_vector_UIWindow__ptr_nlint64 _asgnret_1 = nelua_mipairs_2((&self->Windows));
    function_Po1535aji1YbmWk6 __fornext = _asgnret_1.r1;
    nelua_vector_UIWindow__ptr __forstate = _asgnret_1.r2;
    int64_t __fornextit = _asgnret_1.r3;
    while(true) {
      nlmulret_nlboolean_nlint64_engine_gui_gui_UIWindow_ptr _asgnret_2 = __fornext(__forstate, __fornextit);
      bool __forcont = _asgnret_2.r1;
      uintptr_t i = nelua_assert_narrow_nlint64_nlusize(_asgnret_2.r2);
      engine_gui_gui_UIWindow_ptr window = _asgnret_2.r3;
      if((!__forcont)) {
        break;
      }
      __fornextit = nelua_assert_narrow_nlusize_nlint64(i);
      {
        if(nelua_nlstring___eq(window->windowName, uWindowName)) {
          nelua_vector_Widget__push((&window->Widgets), (engine_gui_gui_Widget){uWidgetName, uWidgetType, uWidgetText, uWidgetFontSize, uWidgetPosition, uWidgetSize, window->borderSize, true, window->borderColor, window->bgColor, window->fgColor, {window->pos.x, window->pos.y}});
          (*(engine_gui_gui_Widget*)nelua_assert_deref(nelua_vector_Widget____atindex((&window->Widgets), nelua_assert_narrow_nlisize_nlusize((nelua_vector_Widget____len((&window->Widgets)) - 1))))).alwaysDrawn = uWidgetAlwaysDrawn;
          (*(engine_gui_gui_Widget*)nelua_assert_deref(nelua_vector_Widget____atindex((&window->Widgets), nelua_assert_narrow_nlisize_nlusize((nelua_vector_Widget____len((&window->Widgets)) - 1))))).autoSize = uAutoSize;
          engine_gui_gui_Widget_Init((&(*(engine_gui_gui_Widget*)nelua_assert_deref(nelua_vector_Widget____atindex((&window->Widgets), nelua_assert_narrow_nlisize_nlusize((nelua_vector_Widget____len((&window->Widgets)) - 1)))))));
          engine_event_manager_event_manager_EventManagerRecord_AddEvent((&engine_event_manager_event_manager_EventManager), uWidgetName);
          {
            nlmulret_function_3dp1Cn41EcGHHu18K_nelua_vector_Widget__ptr_nlint64 _asgnret_3 = nelua_mipairs_3((&window->Widgets));
            function_3dp1Cn41EcGHHu18K __fornext_1 = _asgnret_3.r1;
            nelua_vector_Widget__ptr __forstate_1 = _asgnret_3.r2;
            int64_t __fornextit_1 = _asgnret_3.r3;
            while(true) {
              nlmulret_nlboolean_nlint64_engine_gui_gui_Widget_ptr _asgnret_4 = __fornext_1(__forstate_1, __fornextit_1);
              bool __forcont_1 = _asgnret_4.r1;
              uintptr_t i_1 = nelua_assert_narrow_nlint64_nlusize(_asgnret_4.r2);
              engine_gui_gui_Widget_ptr widget = _asgnret_4.r3;
              if((!__forcont_1)) {
                break;
              }
              __fornextit_1 = nelua_assert_narrow_nlusize_nlint64(i_1);
              {
                if((nelua_nlstring___eq(widget->widgetName, nelua_nlstring___concat_1(window->windowName, ((nlstring){(uint8_t*)"ResetButton", 11}))) || nelua_nlstring___eq(widget->widgetName, nelua_nlstring___concat_1(window->windowName, ((nlstring){(uint8_t*)"MinimiseButton", 14}))))) {
                  widget->isShown = true;
                }
              }
            }
          }
        }
      }
    }
  }
}
void engine_uimanager_uimanager_UIManagerClass_ToggleWindow(engine_uimanager_uimanager_UIManagerClass_ptr self, nlstring uWindowName) {
  {
    nlmulret_function_Po1535aji1YbmWk6_nelua_vector_UIWindow__ptr_nlint64 _asgnret_1 = nelua_mipairs_2((&self->Windows));
    function_Po1535aji1YbmWk6 __fornext = _asgnret_1.r1;
    nelua_vector_UIWindow__ptr __forstate = _asgnret_1.r2;
    int64_t __fornextit = _asgnret_1.r3;
    while(true) {
      nlmulret_nlboolean_nlint64_engine_gui_gui_UIWindow_ptr _asgnret_2 = __fornext(__forstate, __fornextit);
      bool __forcont = _asgnret_2.r1;
      uintptr_t i = nelua_assert_narrow_nlint64_nlusize(_asgnret_2.r2);
      engine_gui_gui_UIWindow_ptr window = _asgnret_2.r3;
      if((!__forcont)) {
        break;
      }
      __fornextit = nelua_assert_narrow_nlusize_nlint64(i);
      {
        if(nelua_nlstring___eq(window->windowName, uWindowName)) {
          window->isShown = (!window->isShown);
        }
      }
    }
  }
}
void engine_uimanager_uimanager_UIManagerClass_ResetWindowPosition(engine_uimanager_uimanager_UIManagerClass_ptr self, nlstring uWindowName) {
  {
    nlmulret_function_Po1535aji1YbmWk6_nelua_vector_UIWindow__ptr_nlint64 _asgnret_1 = nelua_mipairs_2((&self->Windows));
    function_Po1535aji1YbmWk6 __fornext = _asgnret_1.r1;
    nelua_vector_UIWindow__ptr __forstate = _asgnret_1.r2;
    int64_t __fornextit = _asgnret_1.r3;
    while(true) {
      nlmulret_nlboolean_nlint64_engine_gui_gui_UIWindow_ptr _asgnret_2 = __fornext(__forstate, __fornextit);
      bool __forcont = _asgnret_2.r1;
      uintptr_t i = nelua_assert_narrow_nlint64_nlusize(_asgnret_2.r2);
      engine_gui_gui_UIWindow_ptr window = _asgnret_2.r3;
      if((!__forcont)) {
        break;
      }
      __fornextit = nelua_assert_narrow_nlusize_nlint64(i);
      {
        if(nelua_nlstring___eq(window->windowName, uWindowName)) {
          window->pos = window->originalPosition;
        }
      }
    }
  }
}
void engine_uimanager_uimanager_UIManagerClass_Update(engine_uimanager_uimanager_UIManagerClass_ptr self) {
  self->insideElement = false;
  {
    nlmulret_function_Po1535aji1YbmWk6_nelua_vector_UIWindow__ptr_nlint64 _asgnret_1 = nelua_mipairs_2((&self->Windows));
    function_Po1535aji1YbmWk6 __fornext = _asgnret_1.r1;
    nelua_vector_UIWindow__ptr __forstate = _asgnret_1.r2;
    int64_t __fornextit = _asgnret_1.r3;
    while(true) {
      nlmulret_nlboolean_nlint64_engine_gui_gui_UIWindow_ptr _asgnret_2 = __fornext(__forstate, __fornextit);
      bool __forcont = _asgnret_2.r1;
      uintptr_t i = nelua_assert_narrow_nlint64_nlusize(_asgnret_2.r2);
      engine_gui_gui_UIWindow_ptr window = _asgnret_2.r3;
      if((!__forcont)) {
        break;
      }
      __fornextit = nelua_assert_narrow_nlusize_nlint64(i);
      {
        engine_gui_gui_UIWindow_Update(window);
        engine_gui_gui_UIWindow_Draw(window);
        if(engine_event_manager_event_manager_EventManagerRecord_GetEvent((&engine_event_manager_event_manager_EventManager), nelua_nlstring___concat_1(window->windowName, ((nlstring){(uint8_t*)"MinimiseButton", 14}))).fired) {
          engine_uimanager_uimanager_UIManagerClass_ToggleWindow(self, window->windowName);
          engine_event_manager_event_manager_EventManagerRecord_Cleanup((&engine_event_manager_event_manager_EventManager), nelua_nlstring___concat_1(window->windowName, ((nlstring){(uint8_t*)"MinimiseButton", 14})));
        }
        if(engine_event_manager_event_manager_EventManagerRecord_GetEvent((&engine_event_manager_event_manager_EventManager), nelua_nlstring___concat_1(window->windowName, ((nlstring){(uint8_t*)"ResetButton", 11}))).fired) {
          engine_uimanager_uimanager_UIManagerClass_ResetWindowPosition(self, window->windowName);
          engine_event_manager_event_manager_EventManagerRecord_Cleanup((&engine_event_manager_event_manager_EventManager), nelua_nlstring___concat_1(window->windowName, ((nlstring){(uint8_t*)"ResetButton", 11})));
        }
        {
          nlmulret_function_3dp1Cn41EcGHHu18K_nelua_vector_Widget__ptr_nlint64 _asgnret_3 = nelua_mipairs_3((&window->Widgets));
          function_3dp1Cn41EcGHHu18K __fornext_2 = _asgnret_3.r1;
          nelua_vector_Widget__ptr __forstate_2 = _asgnret_3.r2;
          int64_t __fornextit_2 = _asgnret_3.r3;
          while(true) {
            nlmulret_nlboolean_nlint64_engine_gui_gui_Widget_ptr _asgnret_4 = __fornext_2(__forstate_2, __fornextit_2);
            bool __forcont_2 = _asgnret_4.r1;
            uintptr_t i_2 = nelua_assert_narrow_nlint64_nlusize(_asgnret_4.r2);
            engine_gui_gui_Widget_ptr widget = _asgnret_4.r3;
            if((!__forcont_2)) {
              break;
            }
            __fornextit_2 = nelua_assert_narrow_nlusize_nlint64(i_2);
            {
              widget->windowPosition = window->pos;
              widget->isShown = window->isShown;
              engine_gui_gui_Widget_UpdateVW(widget);
              engine_gui_gui_Widget_Update(widget);
              if(engine_utilities__UtilityClass_IsInsideQuad((&engine_utilities__Utility), (Vector2){(float)engine_mouse_mouse_Mouse.x, (float)engine_mouse_mouse_Mouse.y}, widget->tlW, widget->brW)) {
                widget->isHighlighted = true;
                self->insideElement = true;
              }
            }
          }
        }
        if(self->insideElement) {
          engine_mouse_mouse_Mouse.insideUIElement = true;
          window->grabDebounce = 0;
        } else {
          engine_mouse_mouse_Mouse.insideUIElement = false;
        }
      }
    }
  }
}
void engine_uimanager_uimanager_UIManagerClass_AddWindow(engine_uimanager_uimanager_UIManagerClass_ptr self, nlstring uMenuBarText, nlstring uWindowName, Vector2 uSize, Vector2 uPosition, Color uBorderColor, Color uFGColor, Color uBGColor, int uMenuTextPadding, int uMenuFontSize, int uMenuBarSize, int uBorderSize, bool uMenuBarEnabled) {
  nelua_vector_UIWindow__push((&self->Windows), (engine_gui_gui_UIWindow){uMenuBarText, uWindowName, uSize, uPosition, uBorderColor, uFGColor, uBGColor, 0, uMenuTextPadding, uMenuFontSize, uMenuBarSize, uBorderSize, uMenuBarEnabled});
  engine_gui_gui_UIWindow_Init((&(*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_vector_UIWindow____atindex((&self->Windows), nelua_assert_narrow_nlisize_nlusize((nelua_vector_UIWindow____len((&self->Windows)) - 1)))))));
  engine_uimanager_uimanager_UIManagerClass_AddWidget(self, uWindowName, nelua_nlstring___concat_1(uWindowName, ((nlstring){(uint8_t*)"MinimiseButton", 14})), ((nlstring){(uint8_t*)"Button", 6}), ((nlstring){(uint8_t*)"", 0}), 6, (Vector2){(((*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_vector_UIWindow____atindex((&self->Windows), nelua_assert_narrow_nlisize_nlusize((nelua_vector_UIWindow____len((&self->Windows)) - 1))))).size.x - ((*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_vector_UIWindow____atindex((&self->Windows), nelua_assert_narrow_nlisize_nlusize((nelua_vector_UIWindow____len((&self->Windows)) - 1))))).borderSize * 6)) - 20), (float)((*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_vector_UIWindow____atindex((&self->Windows), nelua_assert_narrow_nlisize_nlusize((nelua_vector_UIWindow____len((&self->Windows)) - 1))))).borderSize * 2)}, (Vector2){(float)((*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_vector_UIWindow____atindex((&self->Windows), nelua_assert_narrow_nlisize_nlusize((nelua_vector_UIWindow____len((&self->Windows)) - 1))))).borderSize * (*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_vector_UIWindow____atindex((&self->Windows), nelua_assert_narrow_nlisize_nlusize((nelua_vector_UIWindow____len((&self->Windows)) - 1))))).borderSize), (float)((*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_vector_UIWindow____atindex((&self->Windows), nelua_assert_narrow_nlisize_nlusize((nelua_vector_UIWindow____len((&self->Windows)) - 1))))).borderSize * (*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_vector_UIWindow____atindex((&self->Windows), nelua_assert_narrow_nlisize_nlusize((nelua_vector_UIWindow____len((&self->Windows)) - 1))))).borderSize)}, true, false);
  engine_uimanager_uimanager_UIManagerClass_AddWidget(self, uWindowName, nelua_nlstring___concat_1(uWindowName, ((nlstring){(uint8_t*)"ResetButton", 11})), ((nlstring){(uint8_t*)"Button", 6}), ((nlstring){(uint8_t*)"", 0}), 6, (Vector2){((*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_vector_UIWindow____atindex((&self->Windows), nelua_assert_narrow_nlisize_nlusize((nelua_vector_UIWindow____len((&self->Windows)) - 1))))).size.x - ((*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_vector_UIWindow____atindex((&self->Windows), nelua_assert_narrow_nlisize_nlusize((nelua_vector_UIWindow____len((&self->Windows)) - 1))))).borderSize * 6)), (float)((*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_vector_UIWindow____atindex((&self->Windows), nelua_assert_narrow_nlisize_nlusize((nelua_vector_UIWindow____len((&self->Windows)) - 1))))).borderSize * 2)}, (Vector2){(float)((*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_vector_UIWindow____atindex((&self->Windows), nelua_assert_narrow_nlisize_nlusize((nelua_vector_UIWindow____len((&self->Windows)) - 1))))).borderSize * (*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_vector_UIWindow____atindex((&self->Windows), nelua_assert_narrow_nlisize_nlusize((nelua_vector_UIWindow____len((&self->Windows)) - 1))))).borderSize), (float)((*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_vector_UIWindow____atindex((&self->Windows), nelua_assert_narrow_nlisize_nlusize((nelua_vector_UIWindow____len((&self->Windows)) - 1))))).borderSize * (*(engine_gui_gui_UIWindow*)nelua_assert_deref(nelua_vector_UIWindow____atindex((&self->Windows), nelua_assert_narrow_nlisize_nlusize((nelua_vector_UIWindow____len((&self->Windows)) - 1))))).borderSize)}, true, false);
}
uint16_t nelua_assert_narrow_nlcint_nluint16(int x) {
  if(NELUA_UNLIKELY(x < 0 || x > 0xffff)) {
    nelua_panic_cstring("narrow casting from cint to uint16 failed");
  }
  return (uint16_t)x;
}
int nelua_assert_imod_nlcint(int a, int b) {
  if(NELUA_UNLIKELY(b == -1)) return 0;
  if(NELUA_UNLIKELY(b == 0)) nelua_panic_cstring("division by zero");
  int r = a % b;
  return (r != 0 && (a ^ b) < 0) ? r + b : r;
}
void engine_render_render_RendererClass_BeginRenderIntro(engine_render_render_RendererClass_ptr self) {
  while(self->isRenderingIntro) {
    if((self->frameCount >= 48)) {
      self->isRenderingFrames = false;
    }
    if((self->frameCount >= 54)) {
      self->isRenderingIntro = false;
    }
    Texture localTexture = (Texture){0};
    if(self->isRenderingFrames) {
      localTexture = LoadTexture(nelua_assert_string2cstring(nelua_nlstring___concat_1(((nlstring){(uint8_t*)"engine/intro-manager/resources/frames/TeaEngineIntro-", 53}), nelua_nlstring___concat_1(nelua_tostring_1(self->frameCount), ((nlstring){(uint8_t*)".png", 4})))));
    }
    BeginDrawing();
    ClearBackground((Color){12U, 15U, 16U, 255U});
    if(self->isRenderingFrames) {
      DrawTexture(localTexture, 0, 0, WHITE);
    }
    EndDrawing();
    self->realFrameCount = (self->realFrameCount + 1);
    if((nelua_assert_imod_nlcint(self->realFrameCount, 4) == 0)) {
      self->frameCount = (self->frameCount + 1);
    }
  }
}
void engine_render_render_RendererClass_SetupEngineUI(engine_render_render_RendererClass_ptr self) {
  engine_uimanager_uimanager_UIManagerClass_AddWindow((&engine_uimanager_uimanager_UIManager), ((nlstring){(uint8_t*)"Hierarchy", 9}), ((nlstring){(uint8_t*)"HierarchyWindow", 15}), (Vector2){(float)(main_screenWidth / (double)4), (float)(main_screenHeight - (main_screenHeight / (double)4))}, (Vector2){0.0f, 0.0f}, (Color){15U, 15U, 15U, 255U}, (Color){40U, 40U, 40U, 255U}, (Color){200U, 200U, 200U, 255U}, 8, 12, 32, 4, true);
  engine_uimanager_uimanager_UIManagerClass_AddWindow((&engine_uimanager_uimanager_UIManager), ((nlstring){(uint8_t*)"Inspector", 9}), ((nlstring){(uint8_t*)"InspectorWindow", 15}), (Vector2){(float)(main_screenWidth / (double)4), (float)(main_screenHeight / (double)4)}, (Vector2){(float)(main_screenWidth / (double)4), 0.0f}, (Color){15U, 15U, 15U, 255U}, (Color){40U, 40U, 40U, 255U}, (Color){200U, 200U, 200U, 255U}, 8, 12, 32, 4, true);
  engine_uimanager_uimanager_UIManagerClass_AddWidget((&engine_uimanager_uimanager_UIManager), ((nlstring){(uint8_t*)"InspectorWindow", 15}), ((nlstring){(uint8_t*)"PlayButton", 10}), ((nlstring){(uint8_t*)"Button", 6}), ((nlstring){(uint8_t*)"Play", 4}), 12, (Vector2){16.0f, 48.0f}, (Vector2){40.0f, 24.0f}, false, true);
  engine_uimanager_uimanager_UIManagerClass_AddWidget((&engine_uimanager_uimanager_UIManager), ((nlstring){(uint8_t*)"InspectorWindow", 15}), ((nlstring){(uint8_t*)"StopButton", 10}), ((nlstring){(uint8_t*)"Button", 6}), ((nlstring){(uint8_t*)"Stop", 4}), 12, (Vector2){72.0f, 48.0f}, (Vector2){40.0f, 24.0f}, false, true);
  engine_uimanager_uimanager_UIManagerClass_AddWidget((&engine_uimanager_uimanager_UIManager), ((nlstring){(uint8_t*)"HierarchyWindow", 15}), ((nlstring){(uint8_t*)"PlayButton", 10}), ((nlstring){(uint8_t*)"Button", 6}), ((nlstring){(uint8_t*)"Add", 3}), 12, (Vector2){16.0f, 36.0f}, (Vector2){40.0f, 24.0f}, false, true);
  engine_uimanager_uimanager_UIManagerClass_AddWidget((&engine_uimanager_uimanager_UIManager), ((nlstring){(uint8_t*)"HierarchyWindow", 15}), ((nlstring){(uint8_t*)"SelectButton", 12}), ((nlstring){(uint8_t*)"Selectable", 10}), ((nlstring){(uint8_t*)"A selectable", 12}), 12, (Vector2){16.0f, 64.0f}, (Vector2){40.0f, 24.0f}, false, true);
}
void engine_render_render_RendererClass_Render(engine_render_render_RendererClass_ptr self) {
  ClearBackground((Color){12U, 15U, 16U, 255U});
  engine_uimanager_uimanager_UIManagerClass_Update((&engine_uimanager_uimanager_UIManager));
}
void engine_render_render_RendererClass_Init(engine_render_render_RendererClass_ptr self) {
  engine_render_render_RendererClass_BeginRenderIntro(self);
  main_screenWidth = nelua_assert_narrow_nlcint_nluint16(GetScreenWidth());
  main_screenHeight = nelua_assert_narrow_nlcint_nluint16(GetScreenHeight());
  engine_render_render_RendererClass_SetupEngineUI(self);
}
void nelua_require_engine_render_render(nlniltype modname) {
  engine_render_render_Renderer.isRenderingIntro = true;
  engine_render_render_Renderer.isRenderingFrames = true;
}
int nelua_main(int argc, char** argv) {
  main_screenWidth = nelua_assert_narrow_nlcint_nluint16(GetScreenWidth());
  main_screenHeight = nelua_assert_narrow_nlcint_nluint16(GetScreenHeight());
  nelua_require_engine_render_render(NELUA_NIL);
  main_screenWidth_1 = nelua_assert_narrow_nlcint_nluint16(GetScreenWidth());
  main_screenHeight_1 = nelua_assert_narrow_nlcint_nluint16(GetScreenHeight());
  InitWindow((int)main_screenWidth_1, (int)main_screenHeight_1, (char*)"Game Engine");
  SetWindowPosition(1920, 0);
  if((!IsWindowFullscreen())) {
    ToggleFullscreen();
  }
  SetTargetFPS(60);
  engine_information_handler_information_handler_InformationHandlerClass_Log((&engine_information_handler_information_handler_InformationHandler), nelua_nlstring___concat_1(((nlstring){(uint8_t*)"Project started on: ", 20}), engine_fileystem_filesystem_fs_readfile(((nlstring){(uint8_t*)"age.md", 6})).r1));
  engine_render_render_RendererClass_Init((&engine_render_render_Renderer));
  engine_event_manager_event_manager_EventManagerRecord_RevealEvents((&engine_event_manager_event_manager_EventManager));
  while((!WindowShouldClose())) {
    if(engine_information_handler_information_handler_InformationHandler.isHaulted) {
      goto main_ErrorRaised;
    }
    if(engine_mouse_mouse_Mouse.RMBPressed) {
      engine_information_handler_information_handler_InformationHandlerClass_RaiseError((&engine_information_handler_information_handler_InformationHandler), 1, ((nlstring){(uint8_t*)"RMB was pressed, requesting an exit.", 36}));
    }
    engine_mouse_mouse_MouseClass_Update((&engine_mouse_mouse_Mouse));
    if(engine_mouse_mouse_Mouse.RMBPressed) {
      engine_information_handler_information_handler_InformationHandlerClass_RaiseError((&engine_information_handler_information_handler_InformationHandler), 1, ((nlstring){(uint8_t*)"RMB was pressed, requesting an exit.", 36}));
    }
    BeginDrawing();
    engine_render_render_RendererClass_Render((&engine_render_render_Renderer));
    EndDrawing();
  }
main_ErrorRaised:;
  CloseWindow();
  return 0;
}

