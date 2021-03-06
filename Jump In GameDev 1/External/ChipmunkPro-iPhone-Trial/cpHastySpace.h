/// cpHastySpace is exclusive to Chipmunk Pro
/// Currently it enables ARM NEON optimizations in the solver, but in the future will include other optimizations such as
/// a multi-threaded solver and multi-threaded collision broadphases.

struct cpHastySpace;
typedef struct cpHastySpace cpHastySpace;

/// Create a new hasty space.
/// On ARM platforms that support NEON, this will enable the vectorized solver.
/// cpHastySpace also supports multiple threads, but runs single threaded by default for determinism.
cpSpace *cpHastySpaceNew(void);

void cpHastySpaceFree(cpSpace * space);

/// Set the number of threads to use for the solver.
/// Currently Chipmunk is limited to 2 threads as using more generally provides very minimal performance gains.
/// Passing 0 as the thread count on iOS or OS X will cause Chipmunk to automatically detect the number of threads it should use.
/// On other platforms passing 0 for the thread count will set 1 thread.
void cpHastySpaceSetThreads(cpSpace *space, unsigned int threads);

/// Returns the number of threads the solver is using to run.
unsigned int cpHastySpaceGetThreads(cpSpace * space);

/// When stepping a hasty space, you must use this function.
void cpHastySpaceStep(cpSpace *space, cpFloat dt);
