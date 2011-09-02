double a, b, c, ind, con;
int var_index;












typedef unsigned int size_t;



typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;




__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;







__extension__ typedef long long int __quad_t;
__extension__ typedef unsigned long long int __u_quad_t;


__extension__ typedef __u_quad_t __dev_t;
__extension__ typedef unsigned int __uid_t;
__extension__ typedef unsigned int __gid_t;
__extension__ typedef unsigned long int __ino_t;
__extension__ typedef __u_quad_t __ino64_t;
__extension__ typedef unsigned int __mode_t;
__extension__ typedef unsigned int __nlink_t;
__extension__ typedef long int __off_t;
__extension__ typedef __quad_t __off64_t;
__extension__ typedef int __pid_t;
__extension__ typedef struct
{
  int __val[2];
} __fsid_t;
__extension__ typedef long int __clock_t;
__extension__ typedef unsigned long int __rlim_t;
__extension__ typedef __u_quad_t __rlim64_t;
__extension__ typedef unsigned int __id_t;
__extension__ typedef long int __time_t;
__extension__ typedef unsigned int __useconds_t;
__extension__ typedef long int __suseconds_t;

__extension__ typedef int __daddr_t;
__extension__ typedef long int __swblk_t;
__extension__ typedef int __key_t;


__extension__ typedef int __clockid_t;


__extension__ typedef void *__timer_t;


__extension__ typedef long int __blksize_t;




__extension__ typedef long int __blkcnt_t;
__extension__ typedef __quad_t __blkcnt64_t;


__extension__ typedef unsigned long int __fsblkcnt_t;
__extension__ typedef __u_quad_t __fsblkcnt64_t;


__extension__ typedef unsigned long int __fsfilcnt_t;
__extension__ typedef __u_quad_t __fsfilcnt64_t;

__extension__ typedef int __ssize_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


__extension__ typedef int __intptr_t;


__extension__ typedef unsigned int __socklen_t;
struct _IO_FILE;



typedef struct _IO_FILE FILE;





typedef struct _IO_FILE __FILE;




typedef struct
{
  int __count;
  union
  {

    unsigned int __wch;



    char __wchb[4];
  } __value;
} __mbstate_t;

typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
typedef int _G_int16_t __attribute__ ((__mode__ (__HI__)));
typedef int _G_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int _G_uint16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int _G_uint32_t __attribute__ ((__mode__ (__SI__)));
typedef __builtin_va_list __gnuc_va_list;
struct _IO_jump_t;
struct _IO_FILE;
typedef void _IO_lock_t;





struct _IO_marker
{
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
struct _IO_FILE
{
  int _flags;




  char *_IO_read_ptr;
  char *_IO_read_end;
  char *_IO_read_base;
  char *_IO_write_base;
  char *_IO_write_ptr;
  char *_IO_write_end;
  char *_IO_buf_base;
  char *_IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
  __off64_t _offset;
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;

  int _mode;

  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie, __const char *__buf,
				 size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t * __pos, int __w);


typedef int __io_close_fn (void *__cookie);
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
extern int _IO_getc (_IO_FILE * __fp);
extern int _IO_putc (int __c, _IO_FILE * __fp);
extern int _IO_feof (_IO_FILE * __fp) __attribute__ ((__nothrow__));
extern int _IO_ferror (_IO_FILE * __fp) __attribute__ ((__nothrow__));

extern int _IO_peekc_locked (_IO_FILE * __fp);





extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern int _IO_vfscanf (_IO_FILE * __restrict, const char *__restrict,
			__gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE * __restrict, const char *__restrict,
			 __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);

extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__));




typedef __gnuc_va_list va_list;
typedef __off_t off_t;
typedef __ssize_t ssize_t;







typedef _G_fpos_t fpos_t;







extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;







extern int remove (__const char *__filename) __attribute__ ((__nothrow__));

extern int rename (__const char *__old, __const char *__new)
  __attribute__ ((__nothrow__));




extern int renameat (int __oldfd, __const char *__old, int __newfd,
		     __const char *__new) __attribute__ ((__nothrow__));








extern FILE *tmpfile (void);
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__));





extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__));
extern char *tempnam (__const char *__dir, __const char *__pfx)
  __attribute__ ((__nothrow__)) __attribute__ ((__malloc__));








extern int fclose (FILE * __stream);




extern int fflush (FILE * __stream);

extern int fflush_unlocked (FILE * __stream);






extern FILE *fopen (__const char *__restrict __filename,
		    __const char *__restrict __modes);




extern FILE *freopen (__const char *__restrict __filename,
		      __const char *__restrict __modes,
		      FILE * __restrict __stream);

extern FILE *fdopen (int __fd, __const char *__modes)
  __attribute__ ((__nothrow__));
extern FILE *fmemopen (void *__s, size_t __len, __const char *__modes)
  __attribute__ ((__nothrow__));




extern FILE *open_memstream (char **__bufloc, size_t * __sizeloc)
  __attribute__ ((__nothrow__));






extern void setbuf (FILE * __restrict __stream, char *__restrict __buf)
  __attribute__ ((__nothrow__));



extern int setvbuf (FILE * __restrict __stream, char *__restrict __buf,
		    int __modes, size_t __n) __attribute__ ((__nothrow__));





extern void setbuffer (FILE * __restrict __stream, char *__restrict __buf,
		       size_t __size) __attribute__ ((__nothrow__));


extern void setlinebuf (FILE * __stream) __attribute__ ((__nothrow__));








extern int fprintf (FILE * __restrict __stream,
		    __const char *__restrict __format, ...);




extern int printf (__const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
		    __const char *__restrict __format, ...)
  __attribute__ ((__nothrow__));





extern int vfprintf (FILE * __restrict __s, __const char *__restrict __format,
		     __gnuc_va_list __arg);




extern int vprintf (__const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, __const char *__restrict __format,
		     __gnuc_va_list __arg) __attribute__ ((__nothrow__));





extern int snprintf (char *__restrict __s, size_t __maxlen,
		     __const char *__restrict __format, ...)
  __attribute__ ((__nothrow__))
  __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
		      __const char *__restrict __format, __gnuc_va_list __arg)
  __attribute__ ((__nothrow__))
  __attribute__ ((__format__ (__printf__, 3, 0)));

extern int vdprintf (int __fd, __const char *__restrict __fmt,
		     __gnuc_va_list __arg)
  __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, __const char *__restrict __fmt, ...)
  __attribute__ ((__format__ (__printf__, 2, 3)));








extern int fscanf (FILE * __restrict __stream,
		   __const char *__restrict __format, ...);




extern int scanf (__const char *__restrict __format, ...);

extern int sscanf (__const char *__restrict __s,
		   __const char *__restrict __format, ...)
  __attribute__ ((__nothrow__));
extern int
fscanf (FILE * __restrict __stream, __const char *__restrict __format, ...)
__asm__ ("" "__isoc99_fscanf");
     extern int scanf (__const char *__restrict __format,
		       ...) __asm__ ("" "__isoc99_scanf");
     extern int sscanf (__const char *__restrict __s,
			__const char *__restrict __format,
			...) __asm__ ("" "__isoc99_sscanf")
  __attribute__ ((__nothrow__));








     extern int vfscanf (FILE * __restrict __s,
			 __const char *__restrict __format,
			 __gnuc_va_list __arg)
  __attribute__ ((__format__ (__scanf__, 2, 0)));





     extern int vscanf (__const char *__restrict __format,
			__gnuc_va_list __arg)
  __attribute__ ((__format__ (__scanf__, 1, 0)));


     extern int vsscanf (__const char *__restrict __s,
			 __const char *__restrict __format,
			 __gnuc_va_list __arg) __attribute__ ((__nothrow__))
  __attribute__ ((__format__ (__scanf__, 2, 0)));
     extern int vfscanf (FILE * __restrict __s,
			 __const char *__restrict __format,
			 __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")
  __attribute__ ((__format__ (__scanf__, 2, 0)));
     extern int vscanf (__const char *__restrict __format,
			__gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")
  __attribute__ ((__format__ (__scanf__, 1, 0)));
     extern int vsscanf (__const char *__restrict __s,
			 __const char *__restrict __format,
			 __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf")
  __attribute__ ((__nothrow__))
  __attribute__ ((__format__ (__scanf__, 2, 0)));









     extern int fgetc (FILE * __stream);
     extern int getc (FILE * __stream);





     extern int getchar (void);

     extern int getc_unlocked (FILE * __stream);
     extern int getchar_unlocked (void);
     extern int fgetc_unlocked (FILE * __stream);











     extern int fputc (int __c, FILE * __stream);
     extern int putc (int __c, FILE * __stream);





     extern int putchar (int __c);

     extern int fputc_unlocked (int __c, FILE * __stream);







     extern int putc_unlocked (int __c, FILE * __stream);
     extern int putchar_unlocked (int __c);






     extern int getw (FILE * __stream);


     extern int putw (int __w, FILE * __stream);








     extern char *fgets (char *__restrict __s, int __n,
			 FILE * __restrict __stream);






     extern char *gets (char *__s);

     extern __ssize_t __getdelim (char **__restrict __lineptr,
				  size_t * __restrict __n, int __delimiter,
				  FILE * __restrict __stream);
     extern __ssize_t getdelim (char **__restrict __lineptr,
				size_t * __restrict __n, int __delimiter,
				FILE * __restrict __stream);







     extern __ssize_t getline (char **__restrict __lineptr,
			       size_t * __restrict __n,
			       FILE * __restrict __stream);








     extern int fputs (__const char *__restrict __s,
		       FILE * __restrict __stream);





     extern int puts (__const char *__s);






     extern int ungetc (int __c, FILE * __stream);






     extern size_t fread (void *__restrict __ptr, size_t __size,
			  size_t __n, FILE * __restrict __stream);




     extern size_t fwrite (__const void *__restrict __ptr, size_t __size,
			   size_t __n, FILE * __restrict __s);

     extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
				   size_t __n, FILE * __restrict __stream);
     extern size_t fwrite_unlocked (__const void *__restrict __ptr,
				    size_t __size, size_t __n,
				    FILE * __restrict __stream);








     extern int fseek (FILE * __stream, long int __off, int __whence);




     extern long int ftell (FILE * __stream);




     extern void rewind (FILE * __stream);

     extern int fseeko (FILE * __stream, __off_t __off, int __whence);




     extern __off_t ftello (FILE * __stream);






     extern int fgetpos (FILE * __restrict __stream,
			 fpos_t * __restrict __pos);




     extern int fsetpos (FILE * __stream, __const fpos_t * __pos);



     extern void clearerr (FILE * __stream) __attribute__ ((__nothrow__));

     extern int feof (FILE * __stream) __attribute__ ((__nothrow__));

     extern int ferror (FILE * __stream) __attribute__ ((__nothrow__));




     extern void clearerr_unlocked (FILE * __stream)
  __attribute__ ((__nothrow__));
     extern int feof_unlocked (FILE * __stream) __attribute__ ((__nothrow__));
     extern int ferror_unlocked (FILE * __stream)
  __attribute__ ((__nothrow__));








     extern void perror (__const char *__s);






     extern int sys_nerr;
     extern __const char *__const sys_errlist[];




     extern int fileno (FILE * __stream) __attribute__ ((__nothrow__));




     extern int fileno_unlocked (FILE * __stream)
  __attribute__ ((__nothrow__));
     extern FILE *popen (__const char *__command, __const char *__modes);





     extern int pclose (FILE * __stream);





     extern char *ctermid (char *__s) __attribute__ ((__nothrow__));
     extern void flockfile (FILE * __stream) __attribute__ ((__nothrow__));



     extern int ftrylockfile (FILE * __stream) __attribute__ ((__nothrow__));


     extern void funlockfile (FILE * __stream) __attribute__ ((__nothrow__));


















     enum
     {
       _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
       _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
       _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
       _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
       _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
       _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
       _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
       _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
       _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
       _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
       _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
       _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
     };
     extern __const unsigned short int **__ctype_b_loc (void)
  __attribute__ ((__nothrow__)) __attribute__ ((__const));
     extern __const __int32_t **__ctype_tolower_loc (void)
  __attribute__ ((__nothrow__)) __attribute__ ((__const));
     extern __const __int32_t **__ctype_toupper_loc (void)
  __attribute__ ((__nothrow__)) __attribute__ ((__const));






     extern int isalnum (int) __attribute__ ((__nothrow__));
     extern int isalpha (int) __attribute__ ((__nothrow__));
     extern int iscntrl (int) __attribute__ ((__nothrow__));
     extern int isdigit (int) __attribute__ ((__nothrow__));
     extern int islower (int) __attribute__ ((__nothrow__));
     extern int isgraph (int) __attribute__ ((__nothrow__));
     extern int isprint (int) __attribute__ ((__nothrow__));
     extern int ispunct (int) __attribute__ ((__nothrow__));
     extern int isspace (int) __attribute__ ((__nothrow__));
     extern int isupper (int) __attribute__ ((__nothrow__));
     extern int isxdigit (int) __attribute__ ((__nothrow__));



     extern int tolower (int __c) __attribute__ ((__nothrow__));


     extern int toupper (int __c) __attribute__ ((__nothrow__));








     extern int isblank (int) __attribute__ ((__nothrow__));


     extern int isascii (int __c) __attribute__ ((__nothrow__));



     extern int toascii (int __c) __attribute__ ((__nothrow__));



     extern int _toupper (int) __attribute__ ((__nothrow__));
     extern int _tolower (int) __attribute__ ((__nothrow__));
     typedef struct __locale_struct
     {

       struct __locale_data *__locales[13];


       const unsigned short int *__ctype_b;
       const int *__ctype_tolower;
       const int *__ctype_toupper;


       const char *__names[13];
     } *__locale_t;


     typedef __locale_t locale_t;
     extern int isalnum_l (int, __locale_t) __attribute__ ((__nothrow__));
     extern int isalpha_l (int, __locale_t) __attribute__ ((__nothrow__));
     extern int iscntrl_l (int, __locale_t) __attribute__ ((__nothrow__));
     extern int isdigit_l (int, __locale_t) __attribute__ ((__nothrow__));
     extern int islower_l (int, __locale_t) __attribute__ ((__nothrow__));
     extern int isgraph_l (int, __locale_t) __attribute__ ((__nothrow__));
     extern int isprint_l (int, __locale_t) __attribute__ ((__nothrow__));
     extern int ispunct_l (int, __locale_t) __attribute__ ((__nothrow__));
     extern int isspace_l (int, __locale_t) __attribute__ ((__nothrow__));
     extern int isupper_l (int, __locale_t) __attribute__ ((__nothrow__));
     extern int isxdigit_l (int, __locale_t) __attribute__ ((__nothrow__));

     extern int isblank_l (int, __locale_t) __attribute__ ((__nothrow__));



     extern int __tolower_l (int __c, __locale_t __l)
  __attribute__ ((__nothrow__));
     extern int tolower_l (int __c, __locale_t __l)
  __attribute__ ((__nothrow__));


     extern int __toupper_l (int __c, __locale_t __l)
  __attribute__ ((__nothrow__));
     extern int toupper_l (int __c, __locale_t __l)
  __attribute__ ((__nothrow__));

     typedef int wchar_t;








     union wait
     {
       int w_status;
       struct
       {

	 unsigned int __w_termsig:7;
	 unsigned int __w_coredump:1;
	 unsigned int __w_retcode:8;
	 unsigned int:16;







       } __wait_terminated;
       struct
       {

	 unsigned int __w_stopval:8;
	 unsigned int __w_stopsig:8;
	 unsigned int:16;






       } __wait_stopped;
     };
     typedef union
     {
       union wait *__uptr;
       int *__iptr;
     } __WAIT_STATUS __attribute__ ((__transparent_union__));


     typedef struct
     {
       int quot;
       int rem;
     } div_t;



     typedef struct
     {
       long int quot;
       long int rem;
     } ldiv_t;







     __extension__ typedef struct
     {
       long long int quot;
       long long int rem;
     } lldiv_t;


     extern size_t __ctype_get_mb_cur_max (void)
  __attribute__ ((__nothrow__));




     extern double atof (__const char *__nptr)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1)));

     extern int atoi (__const char *__nptr)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1)));

     extern long int atol (__const char *__nptr)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1)));





     __extension__ extern long long int atoll (__const char *__nptr)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1)));





     extern double strtod (__const char *__restrict __nptr,
			   char **__restrict __endptr)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





     extern float strtof (__const char *__restrict __nptr,
			  char **__restrict __endptr)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));

     extern long double strtold (__const char *__restrict __nptr,
				 char **__restrict __endptr)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





     extern long int strtol (__const char *__restrict __nptr,
			     char **__restrict __endptr, int __base)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));

     extern unsigned long int strtoul (__const char *__restrict __nptr,
				       char **__restrict __endptr, int __base)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));




     __extension__
       extern long long int strtoq (__const char *__restrict __nptr,
				    char **__restrict __endptr, int __base)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));

     __extension__
       extern unsigned long long int strtouq (__const char *__restrict __nptr,
					      char **__restrict __endptr,
					      int __base)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





     __extension__
       extern long long int strtoll (__const char *__restrict __nptr,
				     char **__restrict __endptr, int __base)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));

     __extension__
       extern unsigned long long int strtoull (__const char *__restrict
					       __nptr,
					       char **__restrict __endptr,
					       int __base)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));

     extern char *l64a (long int __n) __attribute__ ((__nothrow__));


     extern long int a64l (__const char *__s)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1)));










     typedef __u_char u_char;
     typedef __u_short u_short;
     typedef __u_int u_int;
     typedef __u_long u_long;
     typedef __quad_t quad_t;
     typedef __u_quad_t u_quad_t;
     typedef __fsid_t fsid_t;




     typedef __loff_t loff_t;



     typedef __ino_t ino_t;
     typedef __dev_t dev_t;




     typedef __gid_t gid_t;




     typedef __mode_t mode_t;




     typedef __nlink_t nlink_t;




     typedef __uid_t uid_t;
     typedef __pid_t pid_t;





     typedef __id_t id_t;
     typedef __daddr_t daddr_t;
     typedef __caddr_t caddr_t;





     typedef __key_t key_t;


     typedef __clock_t clock_t;





     typedef __time_t time_t;



     typedef __clockid_t clockid_t;
     typedef __timer_t timer_t;



     typedef unsigned long int ulong;
     typedef unsigned short int ushort;
     typedef unsigned int uint;
     typedef int int8_t __attribute__ ((__mode__ (__QI__)));
     typedef int int16_t __attribute__ ((__mode__ (__HI__)));
     typedef int int32_t __attribute__ ((__mode__ (__SI__)));
     typedef int int64_t __attribute__ ((__mode__ (__DI__)));


     typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
     typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
     typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
     typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));

     typedef int register_t __attribute__ ((__mode__ (__word__)));


     typedef int __sig_atomic_t;




     typedef struct
     {
       unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
     } __sigset_t;



     typedef __sigset_t sigset_t;





     struct timespec
     {
       __time_t tv_sec;
       long int tv_nsec;
     };

     struct timeval
     {
       __time_t tv_sec;
       __suseconds_t tv_usec;
     };


     typedef __suseconds_t suseconds_t;





     typedef long int __fd_mask;
     typedef struct
     {






       __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];


     }
fd_set;






     typedef __fd_mask fd_mask;

     extern int select (int __nfds, fd_set * __restrict __readfds,
			fd_set * __restrict __writefds,
			fd_set * __restrict __exceptfds,
			struct timeval *__restrict __timeout);
     extern int pselect (int __nfds, fd_set * __restrict __readfds,
			 fd_set * __restrict __writefds,
			 fd_set * __restrict __exceptfds,
			 const struct timespec *__restrict __timeout,
			 const __sigset_t * __restrict __sigmask);





     __extension__
       extern unsigned int gnu_dev_major (unsigned long long int __dev)
  __attribute__ ((__nothrow__));
     __extension__
       extern unsigned int gnu_dev_minor (unsigned long long int __dev)
  __attribute__ ((__nothrow__));
     __extension__
       extern unsigned long long int gnu_dev_makedev (unsigned int __major,
						      unsigned int __minor)
  __attribute__ ((__nothrow__));





     typedef __blksize_t blksize_t;






     typedef __blkcnt_t blkcnt_t;



     typedef __fsblkcnt_t fsblkcnt_t;



     typedef __fsfilcnt_t fsfilcnt_t;
     typedef unsigned long int pthread_t;


     typedef union
     {
       char __size[36];
       long int __align;
     } pthread_attr_t;
     typedef struct __pthread_internal_slist
     {
       struct __pthread_internal_slist *__next;
     } __pthread_slist_t;





     typedef union
     {
       struct __pthread_mutex_s
       {
	 int __lock;
	 unsigned int __count;
	 int __owner;





	 int __kind;





	 unsigned int __nusers;
	 __extension__ union
	 {
	   int __spins;
	   __pthread_slist_t __list;
	 };

       } __data;
       char __size[24];
       long int __align;
     } pthread_mutex_t;

     typedef union
     {
       char __size[4];
       int __align;
     } pthread_mutexattr_t;




     typedef union
     {
       struct
       {
	 int __lock;
	 unsigned int __futex;
	 __extension__ unsigned long long int __total_seq;
	 __extension__ unsigned long long int __wakeup_seq;
	 __extension__ unsigned long long int __woken_seq;
	 void *__mutex;
	 unsigned int __nwaiters;
	 unsigned int __broadcast_seq;
       } __data;
       char __size[48];
       __extension__ long long int __align;
     } pthread_cond_t;

     typedef union
     {
       char __size[4];
       int __align;
     } pthread_condattr_t;



     typedef unsigned int pthread_key_t;



     typedef int pthread_once_t;





     typedef union
     {
       struct
       {
	 int __lock;
	 unsigned int __nr_readers;
	 unsigned int __readers_wakeup;
	 unsigned int __writer_wakeup;
	 unsigned int __nr_readers_queued;
	 unsigned int __nr_writers_queued;


	 unsigned char __flags;
	 unsigned char __shared;
	 unsigned char __pad1;
	 unsigned char __pad2;
	 int __writer;
       } __data;

       char __size[32];
       long int __align;
     } pthread_rwlock_t;

     typedef union
     {
       char __size[8];
       long int __align;
     } pthread_rwlockattr_t;





     typedef volatile int pthread_spinlock_t;




     typedef union
     {
       char __size[20];
       long int __align;
     } pthread_barrier_t;

     typedef union
     {
       char __size[4];
       int __align;
     } pthread_barrierattr_t;









     extern long int random (void) __attribute__ ((__nothrow__));


     extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__));





     extern char *initstate (unsigned int __seed, char *__statebuf,
			     size_t __statelen) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (2)));



     extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (1)));







     struct random_data
     {
       int32_t *fptr;
       int32_t *rptr;
       int32_t *state;
       int rand_type;
       int rand_deg;
       int rand_sep;
       int32_t *end_ptr;
     };

     extern int random_r (struct random_data *__restrict __buf,
			  int32_t * __restrict __result)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

     extern int srandom_r (unsigned int __seed, struct random_data *__buf)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));

     extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
			     size_t __statelen,
			     struct random_data *__restrict __buf)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 4)));

     extern int setstate_r (char *__restrict __statebuf,
			    struct random_data *__restrict __buf)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));






     extern int rand (void) __attribute__ ((__nothrow__));

     extern void srand (unsigned int __seed) __attribute__ ((__nothrow__));




     extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__));







     extern double drand48 (void) __attribute__ ((__nothrow__));
     extern double erand48 (unsigned short int __xsubi[3])
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


     extern long int lrand48 (void) __attribute__ ((__nothrow__));
     extern long int nrand48 (unsigned short int __xsubi[3])
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


     extern long int mrand48 (void) __attribute__ ((__nothrow__));
     extern long int jrand48 (unsigned short int __xsubi[3])
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


     extern void srand48 (long int __seedval) __attribute__ ((__nothrow__));
     extern unsigned short int *seed48 (unsigned short int __seed16v[3])
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
     extern void lcong48 (unsigned short int __param[7])
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





     struct drand48_data
     {
       unsigned short int __x[3];
       unsigned short int __old_x[3];
       unsigned short int __c;
       unsigned short int __init;
       unsigned long long int __a;
     };


     extern int drand48_r (struct drand48_data *__restrict __buffer,
			   double *__restrict __result)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
     extern int erand48_r (unsigned short int __xsubi[3],
			   struct drand48_data *__restrict __buffer,
			   double *__restrict __result)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


     extern int lrand48_r (struct drand48_data *__restrict __buffer,
			   long int *__restrict __result)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
     extern int nrand48_r (unsigned short int __xsubi[3],
			   struct drand48_data *__restrict __buffer,
			   long int *__restrict __result)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


     extern int mrand48_r (struct drand48_data *__restrict __buffer,
			   long int *__restrict __result)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
     extern int jrand48_r (unsigned short int __xsubi[3],
			   struct drand48_data *__restrict __buffer,
			   long int *__restrict __result)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


     extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));

     extern int seed48_r (unsigned short int __seed16v[3],
			  struct drand48_data *__buffer)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

     extern int lcong48_r (unsigned short int __param[7],
			   struct drand48_data *__buffer)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));









     extern void *malloc (size_t __size) __attribute__ ((__nothrow__))
  __attribute__ ((__malloc__));

     extern void *calloc (size_t __nmemb, size_t __size)
  __attribute__ ((__nothrow__)) __attribute__ ((__malloc__));










     extern void *realloc (void *__ptr, size_t __size)
  __attribute__ ((__nothrow__)) __attribute__ ((__warn_unused_result__));

     extern void free (void *__ptr) __attribute__ ((__nothrow__));




     extern void cfree (void *__ptr) __attribute__ ((__nothrow__));










     extern void *alloca (size_t __size) __attribute__ ((__nothrow__));











     extern void *valloc (size_t __size) __attribute__ ((__nothrow__))
  __attribute__ ((__malloc__));




     extern int posix_memalign (void **__memptr, size_t __alignment,
				size_t __size) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (1)));




     extern void abort (void) __attribute__ ((__nothrow__))
  __attribute__ ((__noreturn__));



     extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (1)));





     extern int on_exit (void (*__func) (int __status, void *__arg),
			 void *__arg) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (1)));






     extern void exit (int __status) __attribute__ ((__nothrow__))
  __attribute__ ((__noreturn__));






     extern void _Exit (int __status) __attribute__ ((__nothrow__))
  __attribute__ ((__noreturn__));






     extern char *getenv (__const char *__name) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (1)));




     extern char *__secure_getenv (__const char *__name)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));





     extern int putenv (char *__string) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (1)));





     extern int setenv (__const char *__name, __const char *__value,
			int __replace) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (2)));


     extern int unsetenv (__const char *__name) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (1)));






     extern int clearenv (void) __attribute__ ((__nothrow__));
     extern char *mktemp (char *__template) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (1)));
     extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1)));
     extern int mkstemps (char *__template, int __suffixlen)
  __attribute__ ((__nonnull__ (1)));
     extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (1)));





     extern int system (__const char *__command);

     extern char *realpath (__const char *__restrict __name,
			    char *__restrict __resolved)
  __attribute__ ((__nothrow__));






     typedef int (*__compar_fn_t) (__const void *, __const void *);



     extern void *bsearch (__const void *__key, __const void *__base,
			   size_t __nmemb, size_t __size,
			   __compar_fn_t __compar)
  __attribute__ ((__nonnull__ (1, 2, 5)));



     extern void qsort (void *__base, size_t __nmemb, size_t __size,
			__compar_fn_t __compar)
  __attribute__ ((__nonnull__ (1, 4)));
     extern int abs (int __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern long int labs (long int __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));



     __extension__ extern long long int llabs (long long int __x)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));







     extern div_t div (int __numer, int __denom)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));
     extern ldiv_t ldiv (long int __numer, long int __denom)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));




     __extension__ extern lldiv_t lldiv (long long int __numer,
					 long long int __denom)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));

     extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
			int *__restrict __sign) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (3, 4)));




     extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
			int *__restrict __sign) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (3, 4)));




     extern char *gcvt (double __value, int __ndigit, char *__buf)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3)));




     extern char *qecvt (long double __value, int __ndigit,
			 int *__restrict __decpt, int *__restrict __sign)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4)));
     extern char *qfcvt (long double __value, int __ndigit,
			 int *__restrict __decpt, int *__restrict __sign)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4)));
     extern char *qgcvt (long double __value, int __ndigit, char *__buf)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3)));




     extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
			int *__restrict __sign, char *__restrict __buf,
			size_t __len) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (3, 4, 5)));
     extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
			int *__restrict __sign, char *__restrict __buf,
			size_t __len) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (3, 4, 5)));

     extern int qecvt_r (long double __value, int __ndigit,
			 int *__restrict __decpt, int *__restrict __sign,
			 char *__restrict __buf, size_t __len)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));
     extern int qfcvt_r (long double __value, int __ndigit,
			 int *__restrict __decpt, int *__restrict __sign,
			 char *__restrict __buf, size_t __len)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (3, 4, 5)));







     extern int mblen (__const char *__s, size_t __n)
  __attribute__ ((__nothrow__));


     extern int mbtowc (wchar_t * __restrict __pwc,
			__const char *__restrict __s, size_t __n)
  __attribute__ ((__nothrow__));


     extern int wctomb (char *__s, wchar_t __wchar)
  __attribute__ ((__nothrow__));



     extern size_t mbstowcs (wchar_t * __restrict __pwcs,
			     __const char *__restrict __s, size_t __n)
  __attribute__ ((__nothrow__));

     extern size_t wcstombs (char *__restrict __s,
			     __const wchar_t * __restrict __pwcs, size_t __n)
  __attribute__ ((__nothrow__));








     extern int rpmatch (__const char *__response)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));
     extern int getsubopt (char **__restrict __optionp,
			   char *__const * __restrict __tokens,
			   char **__restrict __valuep)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2, 3)));
     extern int getloadavg (double __loadavg[], int __nelem)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));














     struct tm
     {
       int tm_sec;
       int tm_min;
       int tm_hour;
       int tm_mday;
       int tm_mon;
       int tm_year;
       int tm_wday;
       int tm_yday;
       int tm_isdst;


       long int tm_gmtoff;
       __const char *tm_zone;




     };








     struct itimerspec
     {
       struct timespec it_interval;
       struct timespec it_value;
     };


     struct sigevent;



     extern clock_t clock (void) __attribute__ ((__nothrow__));


     extern time_t time (time_t * __timer) __attribute__ ((__nothrow__));


     extern double difftime (time_t __time1, time_t __time0)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));


     extern time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__));





     extern size_t strftime (char *__restrict __s, size_t __maxsize,
			     __const char *__restrict __format,
			     __const struct tm *__restrict __tp)
  __attribute__ ((__nothrow__));

     extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
			       __const char *__restrict __format,
			       __const struct tm *__restrict __tp,
			       __locale_t __loc)
  __attribute__ ((__nothrow__));



     extern struct tm *gmtime (__const time_t * __timer)
  __attribute__ ((__nothrow__));



     extern struct tm *localtime (__const time_t * __timer)
  __attribute__ ((__nothrow__));





     extern struct tm *gmtime_r (__const time_t * __restrict __timer,
				 struct tm *__restrict __tp)
  __attribute__ ((__nothrow__));



     extern struct tm *localtime_r (__const time_t * __restrict __timer,
				    struct tm *__restrict __tp)
  __attribute__ ((__nothrow__));





     extern char *asctime (__const struct tm *__tp)
  __attribute__ ((__nothrow__));


     extern char *ctime (__const time_t * __timer)
  __attribute__ ((__nothrow__));







     extern char *asctime_r (__const struct tm *__restrict __tp,
			     char *__restrict __buf)
  __attribute__ ((__nothrow__));


     extern char *ctime_r (__const time_t * __restrict __timer,
			   char *__restrict __buf)
  __attribute__ ((__nothrow__));




     extern char *__tzname[2];
     extern int __daylight;
     extern long int __timezone;




     extern char *tzname[2];



     extern void tzset (void) __attribute__ ((__nothrow__));



     extern int daylight;
     extern long int timezone;





     extern int stime (__const time_t * __when) __attribute__ ((__nothrow__));
     extern time_t timegm (struct tm *__tp) __attribute__ ((__nothrow__));


     extern time_t timelocal (struct tm *__tp) __attribute__ ((__nothrow__));


     extern int dysize (int __year) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern int nanosleep (__const struct timespec *__requested_time,
			   struct timespec *__remaining);



     extern int clock_getres (clockid_t __clock_id, struct timespec *__res)
  __attribute__ ((__nothrow__));


     extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp)
  __attribute__ ((__nothrow__));


     extern int clock_settime (clockid_t __clock_id,
			       __const struct timespec *__tp)
  __attribute__ ((__nothrow__));






     extern int clock_nanosleep (clockid_t __clock_id, int __flags,
				 __const struct timespec *__req,
				 struct timespec *__rem);


     extern int clock_getcpuclockid (pid_t __pid, clockid_t * __clock_id)
  __attribute__ ((__nothrow__));




     extern int timer_create (clockid_t __clock_id,
			      struct sigevent *__restrict __evp,
			      timer_t * __restrict __timerid)
  __attribute__ ((__nothrow__));


     extern int timer_delete (timer_t __timerid)
  __attribute__ ((__nothrow__));


     extern int timer_settime (timer_t __timerid, int __flags,
			       __const struct itimerspec *__restrict __value,
			       struct itimerspec *__restrict __ovalue)
  __attribute__ ((__nothrow__));


     extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
  __attribute__ ((__nothrow__));


     extern int timer_getoverrun (timer_t __timerid)
  __attribute__ ((__nothrow__));















     extern void *memcpy (void *__restrict __dest,
			  __const void *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


     extern void *memmove (void *__dest, __const void *__src, size_t __n)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));






     extern void *memccpy (void *__restrict __dest,
			   __const void *__restrict __src, int __c,
			   size_t __n) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (1, 2)));





     extern void *memset (void *__s, int __c, size_t __n)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1)));


     extern int memcmp (__const void *__s1, __const void *__s2, size_t __n)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1, 2)));
     extern void *memchr (__const void *__s, int __c, size_t __n)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1)));




     extern char *strcpy (char *__restrict __dest,
			  __const char *__restrict __src)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

     extern char *strncpy (char *__restrict __dest,
			   __const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


     extern char *strcat (char *__restrict __dest,
			  __const char *__restrict __src)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));

     extern char *strncat (char *__restrict __dest,
			   __const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


     extern int strcmp (__const char *__s1, __const char *__s2)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1, 2)));

     extern int strncmp (__const char *__s1, __const char *__s2, size_t __n)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1, 2)));


     extern int strcoll (__const char *__s1, __const char *__s2)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1, 2)));

     extern size_t strxfrm (char *__restrict __dest,
			    __const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));

     extern int strcoll_l (__const char *__s1, __const char *__s2,
			   __locale_t __l) __attribute__ ((__nothrow__))
  __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));

     extern size_t strxfrm_l (char *__dest, __const char *__src, size_t __n,
			      __locale_t __l) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (2, 4)));





     extern char *strdup (__const char *__s)
  __attribute__ ((__nothrow__)) __attribute__ ((__malloc__))
  __attribute__ ((__nonnull__ (1)));






     extern char *strndup (__const char *__string, size_t __n)
  __attribute__ ((__nothrow__)) __attribute__ ((__malloc__))
  __attribute__ ((__nonnull__ (1)));

     extern char *strchr (__const char *__s, int __c)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1)));
     extern char *strrchr (__const char *__s, int __c)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1)));





     extern size_t strcspn (__const char *__s, __const char *__reject)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1, 2)));


     extern size_t strspn (__const char *__s, __const char *__accept)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1, 2)));
     extern char *strpbrk (__const char *__s, __const char *__accept)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1, 2)));
     extern char *strstr (__const char *__haystack, __const char *__needle)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1, 2)));




     extern char *strtok (char *__restrict __s,
			  __const char *__restrict __delim)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));




     extern char *__strtok_r (char *__restrict __s,
			      __const char *__restrict __delim,
			      char **__restrict __save_ptr)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));

     extern char *strtok_r (char *__restrict __s,
			    __const char *__restrict __delim,
			    char **__restrict __save_ptr)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2, 3)));


     extern size_t strlen (__const char *__s)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1)));





     extern size_t strnlen (__const char *__string, size_t __maxlen)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1)));





     extern char *strerror (int __errnum) __attribute__ ((__nothrow__));

     extern int strerror_r (int __errnum, char *__buf,
			    size_t __buflen) __asm__ ("" "__xpg_strerror_r")
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (2)));
     extern char *strerror_l (int __errnum, __locale_t __l)
  __attribute__ ((__nothrow__));





     extern void __bzero (void *__s, size_t __n) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (1)));



     extern void bcopy (__const void *__src, void *__dest, size_t __n)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));


     extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__))
  __attribute__ ((__nonnull__ (1)));


     extern int bcmp (__const void *__s1, __const void *__s2, size_t __n)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1, 2)));
     extern char *index (__const char *__s, int __c)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1)));
     extern char *rindex (__const char *__s, int __c)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1)));




     extern int ffs (int __i) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern int strcasecmp (__const char *__s1, __const char *__s2)
  __attribute__ ((__nothrow__)) __attribute__ ((__pure__))
  __attribute__ ((__nonnull__ (1, 2)));


     extern int strncasecmp (__const char *__s1, __const char *__s2,
			     size_t __n) __attribute__ ((__nothrow__))
  __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
     extern char *strsep (char **__restrict __stringp,
			  __const char *__restrict __delim)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));




     extern char *strsignal (int __sig) __attribute__ ((__nothrow__));


     extern char *__stpcpy (char *__restrict __dest,
			    __const char *__restrict __src)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
     extern char *stpcpy (char *__restrict __dest,
			  __const char *__restrict __src)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));



     extern char *__stpncpy (char *__restrict __dest,
			     __const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));
     extern char *stpncpy (char *__restrict __dest,
			   __const char *__restrict __src, size_t __n)
  __attribute__ ((__nothrow__)) __attribute__ ((__nonnull__ (1, 2)));













     typedef long double float_t;

     typedef long double double_t;


     extern double acos (double __x) __attribute__ ((__nothrow__));
     extern double __acos (double __x) __attribute__ ((__nothrow__));

     extern double asin (double __x) __attribute__ ((__nothrow__));
     extern double __asin (double __x) __attribute__ ((__nothrow__));

     extern double atan (double __x) __attribute__ ((__nothrow__));
     extern double __atan (double __x) __attribute__ ((__nothrow__));

     extern double atan2 (double __y, double __x)
  __attribute__ ((__nothrow__));
     extern double __atan2 (double __y, double __x)
  __attribute__ ((__nothrow__));


     extern double cos (double __x) __attribute__ ((__nothrow__));
     extern double __cos (double __x) __attribute__ ((__nothrow__));

     extern double sin (double __x) __attribute__ ((__nothrow__));
     extern double __sin (double __x) __attribute__ ((__nothrow__));

     extern double tan (double __x) __attribute__ ((__nothrow__));
     extern double __tan (double __x) __attribute__ ((__nothrow__));




     extern double cosh (double __x) __attribute__ ((__nothrow__));
     extern double __cosh (double __x) __attribute__ ((__nothrow__));

     extern double sinh (double __x) __attribute__ ((__nothrow__));
     extern double __sinh (double __x) __attribute__ ((__nothrow__));

     extern double tanh (double __x) __attribute__ ((__nothrow__));
     extern double __tanh (double __x) __attribute__ ((__nothrow__));



     extern double acosh (double __x) __attribute__ ((__nothrow__));
     extern double __acosh (double __x) __attribute__ ((__nothrow__));

     extern double asinh (double __x) __attribute__ ((__nothrow__));
     extern double __asinh (double __x) __attribute__ ((__nothrow__));

     extern double atanh (double __x) __attribute__ ((__nothrow__));
     extern double __atanh (double __x) __attribute__ ((__nothrow__));







     extern double exp (double __x) __attribute__ ((__nothrow__));
     extern double __exp (double __x) __attribute__ ((__nothrow__));


     extern double frexp (double __x, int *__exponent)
  __attribute__ ((__nothrow__));
     extern double __frexp (double __x, int *__exponent)
  __attribute__ ((__nothrow__));


     extern double ldexp (double __x, int __exponent)
  __attribute__ ((__nothrow__));
     extern double __ldexp (double __x, int __exponent)
  __attribute__ ((__nothrow__));


     extern double log (double __x) __attribute__ ((__nothrow__));
     extern double __log (double __x) __attribute__ ((__nothrow__));


     extern double log10 (double __x) __attribute__ ((__nothrow__));
     extern double __log10 (double __x) __attribute__ ((__nothrow__));


     extern double modf (double __x, double *__iptr)
  __attribute__ ((__nothrow__));
     extern double __modf (double __x, double *__iptr)
  __attribute__ ((__nothrow__));



     extern double expm1 (double __x) __attribute__ ((__nothrow__));
     extern double __expm1 (double __x) __attribute__ ((__nothrow__));


     extern double log1p (double __x) __attribute__ ((__nothrow__));
     extern double __log1p (double __x) __attribute__ ((__nothrow__));


     extern double logb (double __x) __attribute__ ((__nothrow__));
     extern double __logb (double __x) __attribute__ ((__nothrow__));






     extern double exp2 (double __x) __attribute__ ((__nothrow__));
     extern double __exp2 (double __x) __attribute__ ((__nothrow__));


     extern double log2 (double __x) __attribute__ ((__nothrow__));
     extern double __log2 (double __x) __attribute__ ((__nothrow__));








     extern double pow (double __x, double __y) __attribute__ ((__nothrow__));
     extern double __pow (double __x, double __y)
  __attribute__ ((__nothrow__));


     extern double sqrt (double __x) __attribute__ ((__nothrow__));
     extern double __sqrt (double __x) __attribute__ ((__nothrow__));





     extern double hypot (double __x, double __y)
  __attribute__ ((__nothrow__));
     extern double __hypot (double __x, double __y)
  __attribute__ ((__nothrow__));






     extern double cbrt (double __x) __attribute__ ((__nothrow__));
     extern double __cbrt (double __x) __attribute__ ((__nothrow__));








     extern double ceil (double __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern double __ceil (double __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern double fabs (double __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern double __fabs (double __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern double floor (double __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern double __floor (double __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern double fmod (double __x, double __y)
  __attribute__ ((__nothrow__));
     extern double __fmod (double __x, double __y)
  __attribute__ ((__nothrow__));




     extern int __isinf (double __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern int __finite (double __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));





     extern int isinf (double __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern int finite (double __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern double drem (double __x, double __y)
  __attribute__ ((__nothrow__));
     extern double __drem (double __x, double __y)
  __attribute__ ((__nothrow__));



     extern double significand (double __x) __attribute__ ((__nothrow__));
     extern double __significand (double __x) __attribute__ ((__nothrow__));





     extern double copysign (double __x, double __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));
     extern double __copysign (double __x, double __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));






     extern double nan (__const char *__tagb) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern double __nan (__const char *__tagb) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));





     extern int __isnan (double __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));



     extern int isnan (double __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern double j0 (double) __attribute__ ((__nothrow__));
     extern double __j0 (double) __attribute__ ((__nothrow__));
     extern double j1 (double) __attribute__ ((__nothrow__));
     extern double __j1 (double) __attribute__ ((__nothrow__));
     extern double jn (int, double) __attribute__ ((__nothrow__));
     extern double __jn (int, double) __attribute__ ((__nothrow__));
     extern double y0 (double) __attribute__ ((__nothrow__));
     extern double __y0 (double) __attribute__ ((__nothrow__));
     extern double y1 (double) __attribute__ ((__nothrow__));
     extern double __y1 (double) __attribute__ ((__nothrow__));
     extern double yn (int, double) __attribute__ ((__nothrow__));
     extern double __yn (int, double) __attribute__ ((__nothrow__));






     extern double erf (double) __attribute__ ((__nothrow__));
     extern double __erf (double) __attribute__ ((__nothrow__));
     extern double erfc (double) __attribute__ ((__nothrow__));
     extern double __erfc (double) __attribute__ ((__nothrow__));
     extern double lgamma (double) __attribute__ ((__nothrow__));
     extern double __lgamma (double) __attribute__ ((__nothrow__));






     extern double tgamma (double) __attribute__ ((__nothrow__));
     extern double __tgamma (double) __attribute__ ((__nothrow__));





     extern double gamma (double) __attribute__ ((__nothrow__));
     extern double __gamma (double) __attribute__ ((__nothrow__));






     extern double lgamma_r (double, int *__signgamp)
  __attribute__ ((__nothrow__));
     extern double __lgamma_r (double, int *__signgamp)
  __attribute__ ((__nothrow__));







     extern double rint (double __x) __attribute__ ((__nothrow__));
     extern double __rint (double __x) __attribute__ ((__nothrow__));


     extern double nextafter (double __x, double __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));
     extern double __nextafter (double __x, double __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));

     extern double nexttoward (double __x, long double __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));
     extern double __nexttoward (double __x, long double __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));



     extern double remainder (double __x, double __y)
  __attribute__ ((__nothrow__));
     extern double __remainder (double __x, double __y)
  __attribute__ ((__nothrow__));



     extern double scalbn (double __x, int __n) __attribute__ ((__nothrow__));
     extern double __scalbn (double __x, int __n)
  __attribute__ ((__nothrow__));



     extern int ilogb (double __x) __attribute__ ((__nothrow__));
     extern int __ilogb (double __x) __attribute__ ((__nothrow__));




     extern double scalbln (double __x, long int __n)
  __attribute__ ((__nothrow__));
     extern double __scalbln (double __x, long int __n)
  __attribute__ ((__nothrow__));



     extern double nearbyint (double __x) __attribute__ ((__nothrow__));
     extern double __nearbyint (double __x) __attribute__ ((__nothrow__));



     extern double round (double __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern double __round (double __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));



     extern double trunc (double __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern double __trunc (double __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));




     extern double remquo (double __x, double __y, int *__quo)
  __attribute__ ((__nothrow__));
     extern double __remquo (double __x, double __y, int *__quo)
  __attribute__ ((__nothrow__));






     extern long int lrint (double __x) __attribute__ ((__nothrow__));
     extern long int __lrint (double __x) __attribute__ ((__nothrow__));
     extern long long int llrint (double __x) __attribute__ ((__nothrow__));
     extern long long int __llrint (double __x) __attribute__ ((__nothrow__));



     extern long int lround (double __x) __attribute__ ((__nothrow__));
     extern long int __lround (double __x) __attribute__ ((__nothrow__));
     extern long long int llround (double __x) __attribute__ ((__nothrow__));
     extern long long int __llround (double __x)
  __attribute__ ((__nothrow__));



     extern double fdim (double __x, double __y)
  __attribute__ ((__nothrow__));
     extern double __fdim (double __x, double __y)
  __attribute__ ((__nothrow__));


     extern double fmax (double __x, double __y)
  __attribute__ ((__nothrow__));
     extern double __fmax (double __x, double __y)
  __attribute__ ((__nothrow__));


     extern double fmin (double __x, double __y)
  __attribute__ ((__nothrow__));
     extern double __fmin (double __x, double __y)
  __attribute__ ((__nothrow__));



     extern int __fpclassify (double __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern int __signbit (double __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));



     extern double fma (double __x, double __y, double __z)
  __attribute__ ((__nothrow__));
     extern double __fma (double __x, double __y, double __z)
  __attribute__ ((__nothrow__));








     extern double scalb (double __x, double __n)
  __attribute__ ((__nothrow__));
     extern double __scalb (double __x, double __n)
  __attribute__ ((__nothrow__));


     extern float acosf (float __x) __attribute__ ((__nothrow__));
     extern float __acosf (float __x) __attribute__ ((__nothrow__));

     extern float asinf (float __x) __attribute__ ((__nothrow__));
     extern float __asinf (float __x) __attribute__ ((__nothrow__));

     extern float atanf (float __x) __attribute__ ((__nothrow__));
     extern float __atanf (float __x) __attribute__ ((__nothrow__));

     extern float atan2f (float __y, float __x) __attribute__ ((__nothrow__));
     extern float __atan2f (float __y, float __x)
  __attribute__ ((__nothrow__));


     extern float cosf (float __x) __attribute__ ((__nothrow__));
     extern float __cosf (float __x) __attribute__ ((__nothrow__));

     extern float sinf (float __x) __attribute__ ((__nothrow__));
     extern float __sinf (float __x) __attribute__ ((__nothrow__));

     extern float tanf (float __x) __attribute__ ((__nothrow__));
     extern float __tanf (float __x) __attribute__ ((__nothrow__));




     extern float coshf (float __x) __attribute__ ((__nothrow__));
     extern float __coshf (float __x) __attribute__ ((__nothrow__));

     extern float sinhf (float __x) __attribute__ ((__nothrow__));
     extern float __sinhf (float __x) __attribute__ ((__nothrow__));

     extern float tanhf (float __x) __attribute__ ((__nothrow__));
     extern float __tanhf (float __x) __attribute__ ((__nothrow__));



     extern float acoshf (float __x) __attribute__ ((__nothrow__));
     extern float __acoshf (float __x) __attribute__ ((__nothrow__));

     extern float asinhf (float __x) __attribute__ ((__nothrow__));
     extern float __asinhf (float __x) __attribute__ ((__nothrow__));

     extern float atanhf (float __x) __attribute__ ((__nothrow__));
     extern float __atanhf (float __x) __attribute__ ((__nothrow__));







     extern float expf (float __x) __attribute__ ((__nothrow__));
     extern float __expf (float __x) __attribute__ ((__nothrow__));


     extern float frexpf (float __x, int *__exponent)
  __attribute__ ((__nothrow__));
     extern float __frexpf (float __x, int *__exponent)
  __attribute__ ((__nothrow__));


     extern float ldexpf (float __x, int __exponent)
  __attribute__ ((__nothrow__));
     extern float __ldexpf (float __x, int __exponent)
  __attribute__ ((__nothrow__));


     extern float logf (float __x) __attribute__ ((__nothrow__));
     extern float __logf (float __x) __attribute__ ((__nothrow__));


     extern float log10f (float __x) __attribute__ ((__nothrow__));
     extern float __log10f (float __x) __attribute__ ((__nothrow__));


     extern float modff (float __x, float *__iptr)
  __attribute__ ((__nothrow__));
     extern float __modff (float __x, float *__iptr)
  __attribute__ ((__nothrow__));



     extern float expm1f (float __x) __attribute__ ((__nothrow__));
     extern float __expm1f (float __x) __attribute__ ((__nothrow__));


     extern float log1pf (float __x) __attribute__ ((__nothrow__));
     extern float __log1pf (float __x) __attribute__ ((__nothrow__));


     extern float logbf (float __x) __attribute__ ((__nothrow__));
     extern float __logbf (float __x) __attribute__ ((__nothrow__));






     extern float exp2f (float __x) __attribute__ ((__nothrow__));
     extern float __exp2f (float __x) __attribute__ ((__nothrow__));


     extern float log2f (float __x) __attribute__ ((__nothrow__));
     extern float __log2f (float __x) __attribute__ ((__nothrow__));








     extern float powf (float __x, float __y) __attribute__ ((__nothrow__));
     extern float __powf (float __x, float __y) __attribute__ ((__nothrow__));


     extern float sqrtf (float __x) __attribute__ ((__nothrow__));
     extern float __sqrtf (float __x) __attribute__ ((__nothrow__));





     extern float hypotf (float __x, float __y) __attribute__ ((__nothrow__));
     extern float __hypotf (float __x, float __y)
  __attribute__ ((__nothrow__));






     extern float cbrtf (float __x) __attribute__ ((__nothrow__));
     extern float __cbrtf (float __x) __attribute__ ((__nothrow__));








     extern float ceilf (float __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern float __ceilf (float __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern float fabsf (float __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern float __fabsf (float __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern float floorf (float __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern float __floorf (float __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern float fmodf (float __x, float __y) __attribute__ ((__nothrow__));
     extern float __fmodf (float __x, float __y)
  __attribute__ ((__nothrow__));




     extern int __isinff (float __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern int __finitef (float __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));





     extern int isinff (float __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern int finitef (float __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern float dremf (float __x, float __y) __attribute__ ((__nothrow__));
     extern float __dremf (float __x, float __y)
  __attribute__ ((__nothrow__));



     extern float significandf (float __x) __attribute__ ((__nothrow__));
     extern float __significandf (float __x) __attribute__ ((__nothrow__));





     extern float copysignf (float __x, float __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));
     extern float __copysignf (float __x, float __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));






     extern float nanf (__const char *__tagb) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern float __nanf (__const char *__tagb) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));





     extern int __isnanf (float __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));



     extern int isnanf (float __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern float j0f (float) __attribute__ ((__nothrow__));
     extern float __j0f (float) __attribute__ ((__nothrow__));
     extern float j1f (float) __attribute__ ((__nothrow__));
     extern float __j1f (float) __attribute__ ((__nothrow__));
     extern float jnf (int, float) __attribute__ ((__nothrow__));
     extern float __jnf (int, float) __attribute__ ((__nothrow__));
     extern float y0f (float) __attribute__ ((__nothrow__));
     extern float __y0f (float) __attribute__ ((__nothrow__));
     extern float y1f (float) __attribute__ ((__nothrow__));
     extern float __y1f (float) __attribute__ ((__nothrow__));
     extern float ynf (int, float) __attribute__ ((__nothrow__));
     extern float __ynf (int, float) __attribute__ ((__nothrow__));






     extern float erff (float) __attribute__ ((__nothrow__));
     extern float __erff (float) __attribute__ ((__nothrow__));
     extern float erfcf (float) __attribute__ ((__nothrow__));
     extern float __erfcf (float) __attribute__ ((__nothrow__));
     extern float lgammaf (float) __attribute__ ((__nothrow__));
     extern float __lgammaf (float) __attribute__ ((__nothrow__));






     extern float tgammaf (float) __attribute__ ((__nothrow__));
     extern float __tgammaf (float) __attribute__ ((__nothrow__));





     extern float gammaf (float) __attribute__ ((__nothrow__));
     extern float __gammaf (float) __attribute__ ((__nothrow__));






     extern float lgammaf_r (float, int *__signgamp)
  __attribute__ ((__nothrow__));
     extern float __lgammaf_r (float, int *__signgamp)
  __attribute__ ((__nothrow__));







     extern float rintf (float __x) __attribute__ ((__nothrow__));
     extern float __rintf (float __x) __attribute__ ((__nothrow__));


     extern float nextafterf (float __x, float __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));
     extern float __nextafterf (float __x, float __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));

     extern float nexttowardf (float __x, long double __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));
     extern float __nexttowardf (float __x, long double __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));



     extern float remainderf (float __x, float __y)
  __attribute__ ((__nothrow__));
     extern float __remainderf (float __x, float __y)
  __attribute__ ((__nothrow__));



     extern float scalbnf (float __x, int __n) __attribute__ ((__nothrow__));
     extern float __scalbnf (float __x, int __n)
  __attribute__ ((__nothrow__));



     extern int ilogbf (float __x) __attribute__ ((__nothrow__));
     extern int __ilogbf (float __x) __attribute__ ((__nothrow__));




     extern float scalblnf (float __x, long int __n)
  __attribute__ ((__nothrow__));
     extern float __scalblnf (float __x, long int __n)
  __attribute__ ((__nothrow__));



     extern float nearbyintf (float __x) __attribute__ ((__nothrow__));
     extern float __nearbyintf (float __x) __attribute__ ((__nothrow__));



     extern float roundf (float __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern float __roundf (float __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));



     extern float truncf (float __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern float __truncf (float __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));




     extern float remquof (float __x, float __y, int *__quo)
  __attribute__ ((__nothrow__));
     extern float __remquof (float __x, float __y, int *__quo)
  __attribute__ ((__nothrow__));






     extern long int lrintf (float __x) __attribute__ ((__nothrow__));
     extern long int __lrintf (float __x) __attribute__ ((__nothrow__));
     extern long long int llrintf (float __x) __attribute__ ((__nothrow__));
     extern long long int __llrintf (float __x) __attribute__ ((__nothrow__));



     extern long int lroundf (float __x) __attribute__ ((__nothrow__));
     extern long int __lroundf (float __x) __attribute__ ((__nothrow__));
     extern long long int llroundf (float __x) __attribute__ ((__nothrow__));
     extern long long int __llroundf (float __x)
  __attribute__ ((__nothrow__));



     extern float fdimf (float __x, float __y) __attribute__ ((__nothrow__));
     extern float __fdimf (float __x, float __y)
  __attribute__ ((__nothrow__));


     extern float fmaxf (float __x, float __y) __attribute__ ((__nothrow__));
     extern float __fmaxf (float __x, float __y)
  __attribute__ ((__nothrow__));


     extern float fminf (float __x, float __y) __attribute__ ((__nothrow__));
     extern float __fminf (float __x, float __y)
  __attribute__ ((__nothrow__));



     extern int __fpclassifyf (float __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern int __signbitf (float __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));



     extern float fmaf (float __x, float __y, float __z)
  __attribute__ ((__nothrow__));
     extern float __fmaf (float __x, float __y, float __z)
  __attribute__ ((__nothrow__));








     extern float scalbf (float __x, float __n) __attribute__ ((__nothrow__));
     extern float __scalbf (float __x, float __n)
  __attribute__ ((__nothrow__));


     extern long double acosl (long double __x) __attribute__ ((__nothrow__));
     extern long double __acosl (long double __x)
  __attribute__ ((__nothrow__));

     extern long double asinl (long double __x) __attribute__ ((__nothrow__));
     extern long double __asinl (long double __x)
  __attribute__ ((__nothrow__));

     extern long double atanl (long double __x) __attribute__ ((__nothrow__));
     extern long double __atanl (long double __x)
  __attribute__ ((__nothrow__));

     extern long double atan2l (long double __y, long double __x)
  __attribute__ ((__nothrow__));
     extern long double __atan2l (long double __y, long double __x)
  __attribute__ ((__nothrow__));


     extern long double cosl (long double __x) __attribute__ ((__nothrow__));
     extern long double __cosl (long double __x)
  __attribute__ ((__nothrow__));

     extern long double sinl (long double __x) __attribute__ ((__nothrow__));
     extern long double __sinl (long double __x)
  __attribute__ ((__nothrow__));

     extern long double tanl (long double __x) __attribute__ ((__nothrow__));
     extern long double __tanl (long double __x)
  __attribute__ ((__nothrow__));




     extern long double coshl (long double __x) __attribute__ ((__nothrow__));
     extern long double __coshl (long double __x)
  __attribute__ ((__nothrow__));

     extern long double sinhl (long double __x) __attribute__ ((__nothrow__));
     extern long double __sinhl (long double __x)
  __attribute__ ((__nothrow__));

     extern long double tanhl (long double __x) __attribute__ ((__nothrow__));
     extern long double __tanhl (long double __x)
  __attribute__ ((__nothrow__));



     extern long double acoshl (long double __x)
  __attribute__ ((__nothrow__));
     extern long double __acoshl (long double __x)
  __attribute__ ((__nothrow__));

     extern long double asinhl (long double __x)
  __attribute__ ((__nothrow__));
     extern long double __asinhl (long double __x)
  __attribute__ ((__nothrow__));

     extern long double atanhl (long double __x)
  __attribute__ ((__nothrow__));
     extern long double __atanhl (long double __x)
  __attribute__ ((__nothrow__));







     extern long double expl (long double __x) __attribute__ ((__nothrow__));
     extern long double __expl (long double __x)
  __attribute__ ((__nothrow__));


     extern long double frexpl (long double __x, int *__exponent)
  __attribute__ ((__nothrow__));
     extern long double __frexpl (long double __x, int *__exponent)
  __attribute__ ((__nothrow__));


     extern long double ldexpl (long double __x, int __exponent)
  __attribute__ ((__nothrow__));
     extern long double __ldexpl (long double __x, int __exponent)
  __attribute__ ((__nothrow__));


     extern long double logl (long double __x) __attribute__ ((__nothrow__));
     extern long double __logl (long double __x)
  __attribute__ ((__nothrow__));


     extern long double log10l (long double __x)
  __attribute__ ((__nothrow__));
     extern long double __log10l (long double __x)
  __attribute__ ((__nothrow__));


     extern long double modfl (long double __x, long double *__iptr)
  __attribute__ ((__nothrow__));
     extern long double __modfl (long double __x, long double *__iptr)
  __attribute__ ((__nothrow__));



     extern long double expm1l (long double __x)
  __attribute__ ((__nothrow__));
     extern long double __expm1l (long double __x)
  __attribute__ ((__nothrow__));


     extern long double log1pl (long double __x)
  __attribute__ ((__nothrow__));
     extern long double __log1pl (long double __x)
  __attribute__ ((__nothrow__));


     extern long double logbl (long double __x) __attribute__ ((__nothrow__));
     extern long double __logbl (long double __x)
  __attribute__ ((__nothrow__));






     extern long double exp2l (long double __x) __attribute__ ((__nothrow__));
     extern long double __exp2l (long double __x)
  __attribute__ ((__nothrow__));


     extern long double log2l (long double __x) __attribute__ ((__nothrow__));
     extern long double __log2l (long double __x)
  __attribute__ ((__nothrow__));








     extern long double powl (long double __x, long double __y)
  __attribute__ ((__nothrow__));
     extern long double __powl (long double __x, long double __y)
  __attribute__ ((__nothrow__));


     extern long double sqrtl (long double __x) __attribute__ ((__nothrow__));
     extern long double __sqrtl (long double __x)
  __attribute__ ((__nothrow__));





     extern long double hypotl (long double __x, long double __y)
  __attribute__ ((__nothrow__));
     extern long double __hypotl (long double __x, long double __y)
  __attribute__ ((__nothrow__));






     extern long double cbrtl (long double __x) __attribute__ ((__nothrow__));
     extern long double __cbrtl (long double __x)
  __attribute__ ((__nothrow__));








     extern long double ceill (long double __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern long double __ceill (long double __x)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));


     extern long double fabsl (long double __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern long double __fabsl (long double __x)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));


     extern long double floorl (long double __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern long double __floorl (long double __x)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));


     extern long double fmodl (long double __x, long double __y)
  __attribute__ ((__nothrow__));
     extern long double __fmodl (long double __x, long double __y)
  __attribute__ ((__nothrow__));




     extern int __isinfl (long double __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern int __finitel (long double __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));





     extern int isinfl (long double __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern int finitel (long double __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern long double dreml (long double __x, long double __y)
  __attribute__ ((__nothrow__));
     extern long double __dreml (long double __x, long double __y)
  __attribute__ ((__nothrow__));



     extern long double significandl (long double __x)
  __attribute__ ((__nothrow__));
     extern long double __significandl (long double __x)
  __attribute__ ((__nothrow__));





     extern long double copysignl (long double __x, long double __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));
     extern long double __copysignl (long double __x, long double __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));






     extern long double nanl (__const char *__tagb)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));
     extern long double __nanl (__const char *__tagb)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));





     extern int __isnanl (long double __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));



     extern int isnanl (long double __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));


     extern long double j0l (long double) __attribute__ ((__nothrow__));
     extern long double __j0l (long double) __attribute__ ((__nothrow__));
     extern long double j1l (long double) __attribute__ ((__nothrow__));
     extern long double __j1l (long double) __attribute__ ((__nothrow__));
     extern long double jnl (int, long double) __attribute__ ((__nothrow__));
     extern long double __jnl (int, long double)
  __attribute__ ((__nothrow__));
     extern long double y0l (long double) __attribute__ ((__nothrow__));
     extern long double __y0l (long double) __attribute__ ((__nothrow__));
     extern long double y1l (long double) __attribute__ ((__nothrow__));
     extern long double __y1l (long double) __attribute__ ((__nothrow__));
     extern long double ynl (int, long double) __attribute__ ((__nothrow__));
     extern long double __ynl (int, long double)
  __attribute__ ((__nothrow__));






     extern long double erfl (long double) __attribute__ ((__nothrow__));
     extern long double __erfl (long double) __attribute__ ((__nothrow__));
     extern long double erfcl (long double) __attribute__ ((__nothrow__));
     extern long double __erfcl (long double) __attribute__ ((__nothrow__));
     extern long double lgammal (long double) __attribute__ ((__nothrow__));
     extern long double __lgammal (long double) __attribute__ ((__nothrow__));






     extern long double tgammal (long double) __attribute__ ((__nothrow__));
     extern long double __tgammal (long double) __attribute__ ((__nothrow__));





     extern long double gammal (long double) __attribute__ ((__nothrow__));
     extern long double __gammal (long double) __attribute__ ((__nothrow__));






     extern long double lgammal_r (long double, int *__signgamp)
  __attribute__ ((__nothrow__));
     extern long double __lgammal_r (long double, int *__signgamp)
  __attribute__ ((__nothrow__));







     extern long double rintl (long double __x) __attribute__ ((__nothrow__));
     extern long double __rintl (long double __x)
  __attribute__ ((__nothrow__));


     extern long double nextafterl (long double __x, long double __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));
     extern long double __nextafterl (long double __x, long double __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));

     extern long double nexttowardl (long double __x, long double __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));
     extern long double __nexttowardl (long double __x, long double __y)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));



     extern long double remainderl (long double __x, long double __y)
  __attribute__ ((__nothrow__));
     extern long double __remainderl (long double __x, long double __y)
  __attribute__ ((__nothrow__));



     extern long double scalbnl (long double __x, int __n)
  __attribute__ ((__nothrow__));
     extern long double __scalbnl (long double __x, int __n)
  __attribute__ ((__nothrow__));



     extern int ilogbl (long double __x) __attribute__ ((__nothrow__));
     extern int __ilogbl (long double __x) __attribute__ ((__nothrow__));




     extern long double scalblnl (long double __x, long int __n)
  __attribute__ ((__nothrow__));
     extern long double __scalblnl (long double __x, long int __n)
  __attribute__ ((__nothrow__));



     extern long double nearbyintl (long double __x)
  __attribute__ ((__nothrow__));
     extern long double __nearbyintl (long double __x)
  __attribute__ ((__nothrow__));



     extern long double roundl (long double __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern long double __roundl (long double __x)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));



     extern long double truncl (long double __x) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));
     extern long double __truncl (long double __x)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));




     extern long double remquol (long double __x, long double __y, int *__quo)
  __attribute__ ((__nothrow__));
     extern long double __remquol (long double __x, long double __y,
				   int *__quo) __attribute__ ((__nothrow__));






     extern long int lrintl (long double __x) __attribute__ ((__nothrow__));
     extern long int __lrintl (long double __x) __attribute__ ((__nothrow__));
     extern long long int llrintl (long double __x)
  __attribute__ ((__nothrow__));
     extern long long int __llrintl (long double __x)
  __attribute__ ((__nothrow__));



     extern long int lroundl (long double __x) __attribute__ ((__nothrow__));
     extern long int __lroundl (long double __x)
  __attribute__ ((__nothrow__));
     extern long long int llroundl (long double __x)
  __attribute__ ((__nothrow__));
     extern long long int __llroundl (long double __x)
  __attribute__ ((__nothrow__));



     extern long double fdiml (long double __x, long double __y)
  __attribute__ ((__nothrow__));
     extern long double __fdiml (long double __x, long double __y)
  __attribute__ ((__nothrow__));


     extern long double fmaxl (long double __x, long double __y)
  __attribute__ ((__nothrow__));
     extern long double __fmaxl (long double __x, long double __y)
  __attribute__ ((__nothrow__));


     extern long double fminl (long double __x, long double __y)
  __attribute__ ((__nothrow__));
     extern long double __fminl (long double __x, long double __y)
  __attribute__ ((__nothrow__));



     extern int __fpclassifyl (long double __value)
  __attribute__ ((__nothrow__)) __attribute__ ((__const__));


     extern int __signbitl (long double __value) __attribute__ ((__nothrow__))
  __attribute__ ((__const__));



     extern long double fmal (long double __x, long double __y,
			      long double __z) __attribute__ ((__nothrow__));
     extern long double __fmal (long double __x, long double __y,
				long double __z)
  __attribute__ ((__nothrow__));








     extern long double scalbl (long double __x, long double __n)
  __attribute__ ((__nothrow__));
     extern long double __scalbl (long double __x, long double __n)
  __attribute__ ((__nothrow__));
     extern int signgam;
     enum
     {
       FP_NAN,

       FP_INFINITE,

       FP_ZERO,

       FP_SUBNORMAL,

       FP_NORMAL
     };
     typedef enum
     {
       _IEEE_ = -1,
       _SVID_,
       _XOPEN_,
       _POSIX_,
       _ISOC_
     } _LIB_VERSION_TYPE;




     extern _LIB_VERSION_TYPE _LIB_VERSION;
     struct exception
     {
       int type;
       char *name;
       double arg1;
       double arg2;
       double retval;
     };




     extern int matherr (struct exception *__exc);




     typedef enum
     {
       false, true
     } bool;


     typedef struct
     {
       int index;
       int control;
       int bufsize;
       char buffer[100000][30];
       bool save;
     } loopstack;


     typedef struct
     {
       char mode[30];
       bool enabled;
     } mode;

     typedef struct
     {
       char name[30];
       double value;
     } const_list;


     typedef struct
     {
       double *contents;
       int maxSize;
       int top;
     } stackT;


     void StackInit (stackT * stackP, int maxSize)
{
  double *newContents;
  newContents = (double *) malloc (sizeof (double) * maxSize);
  if (newContents == ((void *) 0))
    {
      fprintf (stderr, "Not enough memory.\n");
      exit (1);
    }
  stackP->contents = newContents;
  stackP->maxSize = maxSize;
  stackP->top = -1;
}


void
StackDestroy (stackT * stackP)
{
  free (stackP->contents);
  stackP->contents = ((void *) 0);
  stackP->maxSize = 0;
  stackP->top = -1;
}


int
StackIsEmpty (stackT * stackP)
{
  return stackP->top < 0;
}


int
StackIsFull (stackT * stackP)
{
  return stackP->top >= stackP->maxSize - 1;
}


void
StackPush (stackT * stackP, double element)
{
  if (StackIsFull (stackP))
    {
      fprintf (stderr, "Can't push element: stack is full.\n");
      exit (1);
    }
  stackP->contents[++stackP->top] = element;
}


double
StackPop (stackT * stackP)
{
  if (StackIsEmpty (stackP))
    {
      fprintf (stderr, "Can't pop element: stack is empty.\n");
      exit (1);
    }
  return stackP->contents[stackP->top--];
}


void
StackShow (stackT * stackP)
{
  if (stackP->top == -1)
    {
      printf ("[ ]\n");
    }
  else if (stackP->top == 0)
    {
      printf ("~[ %.2f ]\n", stackP->contents[0]);
    }
  else if (stackP->top > 0)
    {
      int i;
      printf ("~[ ");
      for (i = 0; i < stackP->top; i++)
	{
	  printf ("%.2f, ", stackP->contents[i]);
	}
      printf ("%.2f ]\n", stackP->contents[stackP->top]);
    }
}

void
StackShowVert (stackT * stackP)
{
  if (stackP->top == -1)
    {
      printf ("-top-\n-end-\n");
    }
  else if (stackP->top == 0)
    {
      printf ("-top-\n~%.2f\n-end-\n", stackP->contents[0]);
    }
  else if (stackP->top > 0)
    {
      int i;
      printf ("-top-\n");
      for (i = stackP->top; i >= 0; i--)
	{
	  printf ("~%.2f\n", stackP->contents[i]);
	}
      printf ("-end-\n");
    }
}

bool
str_in_arr (int argc, char *argv[], char *match)
{
  int i;
  for (i = 0; i < argc; i++)
    if (!strcmp (match, argv[i]))
      return 1;
  return 0;
}

bool
char_in_arr (char tosearch, char arr[])
{
  int i = 0;
  for (; i < strlen (arr); i++)
    {
      if (arr[i] == tosearch)
	{
	  return true;
	}
    }
  return false;
}


void
error (char *msg)
{
  printf ("error: %s\n", msg);
}


void
ret (double msg)
{
  printf ("%.2f\n", msg);
}


void
plus (stackT * dataStack)
{
  if (dataStack->top < 1)
    {
      StackPush (dataStack, 0);
      plus (dataStack);
    }
  else
    {
      b = StackPop (dataStack);
      a = StackPop (dataStack);
      StackPush (dataStack, a + b);
    }
}


void
plusplus (stackT * dataStack)
{
  if (dataStack->top < 1)
    {
      StackPush (dataStack, 0);
      plus (dataStack);
    }
  else
    {
      while (dataStack->top >= 1)
	{
	  plus (dataStack);
	}
    }
}


void
mul (stackT * dataStack)
{
  if (dataStack->top < 1)
    {
      StackPush (dataStack, 1);
      mul (dataStack);
    }
  else
    {
      b = StackPop (dataStack);
      a = StackPop (dataStack);
      StackPush (dataStack, a * b);

    }
}


void
mulmul (stackT * dataStack)
{
  if (dataStack->top < 1)
    {
      StackPush (dataStack, 1);
      mulmul (dataStack);
    }
  else
    {
      while (dataStack->top >= 1)
	{
	  mul (dataStack);
	}
    }
}


void
showtop (stackT * dataStack)
{
  if (StackIsEmpty (dataStack))
    {
      error ("stack is empty!");
    }
  else
    {
      printf ("~%.2f\n", dataStack->contents[dataStack->top]);
    }
}


void
drop (stackT * dataStack, bool show)
{
  if (StackIsEmpty (dataStack))
    {
      error ("stack is empty!");
    }
  else
    {
      if (show)
	{
	  ret (StackPop (dataStack));
	}
      else
	{
	  StackPop (dataStack);
	}
    }
}


void
delstack (stackT * dataStack)
{
  if (!StackIsEmpty (dataStack))
    {
      while (dataStack->top > -1)
	{
	  drop (dataStack, false);
	}
    }
}


void
show (stackT * dataStack)
{
  printf ("");
  StackShow (dataStack);
}


void
sub (stackT * dataStack)
{
  if (dataStack->top < 1)
    {
      StackPush (dataStack, 0);
      sub (dataStack);
    }
  else
    {
      b = StackPop (dataStack);
      a = StackPop (dataStack);
      StackPush (dataStack, a - b);
    }
}


void
swap (stackT * dataStack)
{
  if (dataStack->top < 1)
    {
      error ("not enough frames!");
    }
  else
    {
      b = StackPop (dataStack);
      a = StackPop (dataStack);
      StackPush (dataStack, b);
      StackPush (dataStack, a);
    }
}


void
duplicate (stackT * dataStack, int num)
{
  if (dataStack->top < num)
    {
      error ("stack is empty!");
    }
  else
    {
      StackPush (dataStack, dataStack->contents[dataStack->top - num]);
    }
}


void
jump (stackT * dataStack)
{
  if (StackIsEmpty (dataStack))
    {
      error ("stack is empty!");
    }
  else
    {
      a = StackPop (dataStack) + 1;
      if (a > dataStack->top)
	{
	  error ("not enough frames!");
	}
      else
	{
	  ret (dataStack->contents[(int) a]);
	}
    }
}


void
range (stackT * dataStack)
{
  if (dataStack->top < 1)
    {
      error ("not enough frames!");
    }
  else
    {
      b = StackPop (dataStack);
      a = StackPop (dataStack);
      if (a < b)
	{
	  for (c = a; c <= b; c++)
	    {
	      StackPush (dataStack, c);
	    }
	}
      else if (a > b)
	{
	  for (c = a; c >= b; c--)
	    {
	      StackPush (dataStack, c);
	    }
	}
      else if (a == b)
	{
	  StackPush (dataStack, a);
	}
    }
}


void
outascii (stackT * dataStack)
{
  if (dataStack->top < 0)
    {
      error ("not enough frames!");
    }
  else
    {
      printf ("%c\n", (unsigned char) StackPop (dataStack));
    }
}


void
allascii (stackT * dataStack)
{
  if (dataStack->top < 0)
    {
      error ("not enough frames!");
    }
  else
    {
      printf ("");
      for (a = 0; a < dataStack->top + 1; a++)
	{
	  printf ("%c", (unsigned char) dataStack->contents[(int) a]);
	}
      printf ("\n");
      delstack (dataStack);
    }
}


void
divide (stackT * dataStack)
{
  if (dataStack->top < 1)
    {
      error ("not enough frames!");
    }
  else
    {
      b = StackPop (dataStack);
      a = StackPop (dataStack);
      StackPush (dataStack, a / b);
    }
}


int
toggle (mode * list, int index)
{
  if (index < 0)
    {
      error ("toggle error: no such mode!");
      return 0;
    }
  else
    {
      list[index].enabled = !(list[index].enabled);
      return 1;
    }
}


int
lookup (mode * list, char *mode)
{
  for (a = 0; a < 3; a++)
    {
      if (!strcmp (list[(int) a].mode, mode))
	{
	  return (int) a;
	}
    }
  return -1;
}

int
c_lookup (const_list * list, char *const_name)
{
  for (a = 0; a < 5; a++)
    {
      if (!strcmp (list[(int) a].name, const_name))
	{
	  return (int) a;
	}
    }
  return -1;
}


int
is_enabled (mode * list, char *mode)
{
  a = lookup (list, mode);
  if (a < 0)
    {
      printf ("error: is_enabled error: %s -  no such mode!", mode);
      return 0;
    }
  return list[lookup (list, mode)].enabled;
}

double
dopow (double a, double b)
{
  int i;
  for (i = 0; i < b; i++)
    {
      a *= a;
    }
  return a;
}

void
powers (stackT * dataStack)
{
  if (dataStack->top < 1)
    {
      StackPush (dataStack, 1.0);
      powers (dataStack);
    }
  else
    {
      b = StackPop (dataStack);
      a = StackPop (dataStack);
      StackPush (dataStack, pow (a, b));
    }
}

void
modulus (stackT * dataStack)
{
  if (dataStack->top < 1)
    {
      StackPush (dataStack, 1.0);
      modulus (dataStack);
    }
  else
    {
      b = StackPop (dataStack);
      a = StackPop (dataStack);
      StackPush (dataStack, (int) a % (int) b);
    }
}

double
deg2rad (double degrees)
{
  return (3.14159265358979323846 / 180) * degrees;
}

double
rad2deg (double radians)
{
  return (180 / 3.14159265358979323846) * radians;
}

void
tangent (stackT * dataStack)
{
  if (dataStack->top < 0)
    {
      error ("stack is empty!");
    }
  else
    {
      StackPush (dataStack, tan (deg2rad (StackPop (dataStack))));
    }
}

void
sine (stackT * dataStack)
{
  if (dataStack->top < 0)
    {
      error ("stack is empty!");
    }
  else
    {
      StackPush (dataStack, sin (deg2rad (StackPop (dataStack))));
    }
}

void
cosine (stackT * dataStack)
{
  if (dataStack->top < 0)
    {
      error ("stack is empty!");
    }
  else
    {
      StackPush (dataStack, cos (deg2rad (StackPop (dataStack))));
    }
}

void
userin (stackT * dataStack)
{
  char cmd[20];
  if (dataStack->top < 0)
    {
      StackPush (dataStack, (double) 1);
      userin (dataStack);
    }
  else
    {
      a = StackPop (dataStack);
      while (a > 0)
	{
	  printf ("%d: ", (int) a);
	  scanf ("%s", cmd);
	  StackPush (dataStack, atof (cmd));
	  a--;
	}
    }
}

void
gt (stackT * dataStack)
{
  if (dataStack->top < 1)
    {
      error ("nor enough frames!");
    }
  else
    {
      b = StackPop (dataStack);
      a = StackPop (dataStack);
      StackPush (dataStack, (double) a > b);
    }
}

void
lt (stackT * dataStack)
{
  if (dataStack->top < 1)
    {
      error ("not enough frames!");
    }
  else
    {
      b = StackPop (dataStack);
      a = StackPop (dataStack);
      StackPush (dataStack, (double) a < b);
    }
}

void
eqeq (stackT * dataStack)
{
  if (dataStack->top < 1)
    {
      error ("not enough frames!");
    }
  else
    {
      b = StackPop (dataStack);
      a = StackPop (dataStack);
      StackPush (dataStack, (double) a == b);
    }
}

void
gteq (stackT * dataStack)
{
  if (dataStack->top < 1)
    {
      error ("not enough frames!");
    }
  else
    {
      b = StackPop (dataStack);
      a = StackPop (dataStack);
      StackPush (dataStack, (double) a >= b);
    }
}

void
lteq (stackT * dataStack)
{
  if (dataStack->top < 1)
    {
      error ("not enough frames!");
    }
  else
    {
      b = StackPop (dataStack);
      a = StackPop (dataStack);
      StackPush (dataStack, (double) a <= b);
    }
}

void
log_and (stackT * dataStack)
{
  if (dataStack->top < 1)
    {
      error ("not enough frames!");
    }
  else
    {
      b = StackPop (dataStack);
      a = StackPop (dataStack);
      StackPush (dataStack, a && b);
    }
}

void
log_or (stackT * dataStack)
{
  if (dataStack->top < 1)
    {
      error ("not enough frames!");
    }
  else
    {
      b = StackPop (dataStack);
      a = StackPop (dataStack);
      StackPush (dataStack, a || b);
    }
}

int cmds;
int top;
double variables[100000];


int
eval (stackT * dataStack, loopstack * loopStack, mode list[3], char cmd[],
      const_list cons[5])
{

  char msg[30];

  if ((cmd[0] == '-')
      &&
      (((*__ctype_b_loc ())[(int) ((cmd[1]))] & (unsigned short int) _ISdigit)
       || cmd[1] == '.'))
    {
      StackPush (dataStack, atof (cmd));
    }
  else
    if (((*__ctype_b_loc ())[(int) ((cmd[0]))] & (unsigned short int)
	 _ISdigit) || ((cmd[0] == '.')
		       && ((*__ctype_b_loc ())[(int) ((cmd[1]))] &
			   (unsigned short int) _ISdigit)))
    {
      StackPush (dataStack, atof (cmd));
    }
  else if (!strcmp (cmd, "<>"))
    {
      StackPush (dataStack, (int) ' ');
    }
  else if ((cmd[0] == '\'') || (cmd[0] == '`'))
    {
      if (strlen (cmd) > 1)
	{
	  for (a = 1; a < strlen (cmd); a++)
	    {
	      StackPush (dataStack, (int) cmd[(int) a]);
	    }
	}
      else
	{
	  error ("not a valid char/string!");
	}
    }

  else
    {

      for (c = 0; c < strlen (cmd); c++)
	{
	  cmd[(int) c] = tolower (cmd[(int) c]);
	}

      if ((cmd[0] == '@') && (strlen (cmd) > 1))
	{
	  a = toggle (list, lookup (list, cmd));
	  if (a)
	    {
	      printf ("--%s %s--\n", cmd,
		      is_enabled (list, cmd) ? "ON" : "OFF");
	    }
	}

      else if (cmd[0] == '#')
	{
	  if (strlen (cmd) > 1)
	    {
	      if (c_lookup (cons, cmd) != -1)
		{
		  StackPush (dataStack, cons[c_lookup (cons, cmd)].value);
		}
	    }
	  else
	    {
	      error ("not enough frames!");
	    }
	}

      else if (!strcmp (cmd, "and"))
	{
	  log_and (dataStack);
	}

      else if (!strcmp (cmd, "or"))
	{
	  log_or (dataStack);
	}

      else if ((cmd[0] == '!') && (strlen (cmd) > 1) && (cmd[1] >= '-')
	       && (cmd[1] <= '9'))
	{
	  var_index = atoi (cmd + 1);
	  if (dataStack->top >= 0)
	    {
	      variables[var_index] = StackPop (dataStack);
	    }
	  else
	    {
	      error ("stack is empty!");
	    }
	}

      else if (!strcmp (cmd, "pow"))
	{
	  powers (dataStack);
	}

      else if (!strcmp (cmd, "mod"))
	{
	  modulus (dataStack);
	}

      else if (!strcmp (cmd, "tan"))
	{
	  tangent (dataStack);
	}

      else if (!strcmp (cmd, "sin"))
	{
	  sine (dataStack);
	}

      else if (!strcmp (cmd, "cos"))
	{
	  cosine (dataStack);
	}

      else if (!strcmp (cmd, "read"))
	{
	  userin (dataStack);
	}

      else if (!strcmp (cmd, ">"))
	{
	  gt (dataStack);
	}

      else if (!strcmp (cmd, "<"))
	{
	  lt (dataStack);
	}

      else if (!strcmp (cmd, "="))
	{
	  eqeq (dataStack);
	}

      else if (!strcmp (cmd, "<="))
	{
	  lteq (dataStack);
	}

      else if (!strcmp (cmd, ">="))
	{
	  gteq (dataStack);
	}

      else if ((cmd[0] == '&') && (strlen (cmd) > 1) && (cmd[1] >= '-')
	       && (cmd[1] <= '9'))
	{
	  var_index = atoi (cmd + 1);
	  printf ("ind: %d\n", var_index);
	  StackPush (dataStack, variables[var_index]);
	}


      else if (!strcmp (cmd, "mode"))
	{
	  for (a = 0; a < 3; a++)
	    {
	      if (list[(int) a].enabled)
		{
		  printf ("%s   ", list[(int) a].mode);
		}
	    }
	  printf ("\n");
	}


      else if (!strcmp (cmd, "modes"))
	{
	  for (a = 0; a < 3; a++)
	    {
	      printf ("%s:%d   ", list[(int) a].mode,
		      is_enabled (list, list[(int) a].mode));
	    }
	  printf ("\n");
	}

      else if (!strcmp (cmd, "+"))
	{
	  plus (dataStack);
	}

      else if (!strcmp (cmd, "++"))
	{
	  plusplus (dataStack);
	}

      else if (!strcmp (cmd, "**"))
	{
	  mulmul (dataStack);
	}

      else if (!strcmp (cmd, "."))
	{
	  showtop (dataStack);
	}

      else if (!strcmp (cmd, "*"))
	{
	  mul (dataStack);
	}

      else if (!strcmp (cmd, ".."))
	{
	  delstack (dataStack);
	}

      else if (!strcmp (cmd, "show"))
	{
	  StackShowVert (dataStack);
	}

      else if (!strcmp (cmd, "-"))
	{
	  sub (dataStack);
	}

      else if (!strcmp (cmd, "swap"))
	{
	  swap (dataStack);
	}

      else if (!strcmp (cmd, "dup"))
	{
	  duplicate (dataStack, 0);
	}

      else if (!strcmp (cmd, "jump"))
	{
	  jump (dataStack);
	}

      else if (!strcmp (cmd, "range"))
	{
	  range (dataStack);
	}

      else if (!strcmp (cmd, "drop") || !strcmp (cmd, "pop"))
	{
	  drop (dataStack, true);
	}

      else if (!strcmp (cmd, "over"))
	{
	  duplicate (dataStack, 1);
	}

      else if (!strcmp (cmd, "wover"))
	{
	  duplicate (dataStack, 2);
	}

      else if (!strcmp (cmd, "top"))
	{
	  StackPush (dataStack, dataStack->top);
	}

      else if (!strcmp (cmd, "outascii"))
	{
	  outascii (dataStack);
	}

      else if (!strcmp (cmd, "allascii"))
	{
	  allascii (dataStack);
	}

      else if (!strcmp (cmd, "/"))
	{
	  divide (dataStack);
	}


      else if (!strcmp (cmd, "tot"))
	{
	  printf ("tot: %d\n", cmds);
	}


      else if (!strcmp (cmd, "reset"))
	{
	  cmds = 0;
	}


      else if (!strcmp (cmd, "["))
	{
	  if (dataStack->top < 1)
	    {
	      error ("not enough frames!");
	    }
	  else
	    {
	      loopStack->index = (int) StackPop (dataStack);
	      loopStack->control = (int) StackPop (dataStack) + 1;
	    }
	  loopStack->save = true;
	}


      else if (!strcmp (cmd, "i"))
	{
	  StackPush (dataStack, loopStack->index);
	}


      else if (strcmp (cmd, "]") == 0)
	{
	  loopStack->index += 1;

	  if (loopStack->index <= loopStack->control)
	    {
	      for (c = 0; c < loopStack->bufsize; c++)
		{


		  eval (dataStack, loopStack, list,
			loopStack->buffer[(int) c], cons);
		}
	    }
	  else
	    {
	      loopStack->index = 0;
	      loopStack->control = 0;
	      memset (loopStack->buffer, '\0',
		      sizeof (loopStack->buffer) * 100000 * 30);
	      loopStack->bufsize = 0;
	      loopStack->save = false;
	    }
	}


      else
	{
	  if ((cmd[0] != '@') && strcmp (cmd, "end") && (cmd[0] != '#'))
	    {
	      sprintf (msg, "%s - unknown command!", cmd);
	      error (msg);
	    }
	}


      if (loopStack->save && strcmp (cmd, "["))
	{
	  *loopStack->buffer[loopStack->bufsize++] = *cmd;
	}
    }


  if (cmd[0] != '@')
    {
      if (is_enabled (list, "@transparent") && strcmp (cmd, "show")
	  && strcmp (cmd, "tot") && strcmp (cmd, "reset")
	  && strcmp (cmd, "end") && strcmp (cmd, ".") && strcmp (cmd, ".."))
	{
	  printf ("%s | ", cmd);
	  StackShow (dataStack);
	}
      if (is_enabled (list, "@tracker") && strcmp (cmd, "tot")
	  && strcmp (cmd, "reset"))
	{
	  cmds++;
	}
      if (!is_enabled (list, "@tracker") && (cmds != 0))
	{
	  cmds = 0;
	}
    }
}


int
main (int argc, char *argv[])
{
  FILE *fp;
  FILE *tmp;




  stackT dataStack;


  loopstack loopStack;


  mode list[] = {
    {"@default", true},
    {"@transparent", false},
    {"@tracker", false},
  };

  const_list cons[] = {
    {"#t", 1},
    {"#true", 1},
    {"#f", 0},
    {"#false", 0},
    {"#pi", 3.14159265358979323846},
  };
  loopStack.bufsize = 0;
  loopStack.save = false;

  StackInit (&dataStack, 100000);
  char cmd[30] = "00";
  cmds = 0;
  if (argc > 1)
    {
      if (str_in_arr (argc, argv, "-v")
	  || str_in_arr (argc, argv, "--version"))
	{
	  printf ("%s %.1f on %s\n", "gecho", 0.5, "Unix");
	  exit (1);
	}
      fp = fopen (argv[1], "r");
      if (fp != ((void *) 0))
	{
	  while (strcmp (cmd, "end"))
	    {
	      fscanf (fp, "%s", cmd);
	      eval (&dataStack, &loopStack, list, cmd, cons);
	    }
	  fclose (fp);
	  if (!str_in_arr (argc, argv, "--shell"))
	    {
	      exit (1);
	    }
	}
      else
	{
	  printf ("error: %s - no such file!\n", argv[1]);
	  exit (1);
	}
    }

  printf ("%s %.1f on %s\n\n", "gecho", 0.5, "Unix");


  while (1)
    {
      scanf ("%s", cmd);
      if (!strcmp (cmd, "quit") || !strcmp (cmd, "exit"))
	{
	  printf ("\nbye\n");
	  break;
	}
      eval (&dataStack, &loopStack, list, cmd, cons);
    }
}
