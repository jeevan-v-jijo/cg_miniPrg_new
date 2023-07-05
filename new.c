#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>

int main() {
    ilInit();
    iluInit();
    ilutRenderer(ILUT_OPENGL);
    
    ilShutDown();
    

    return 0;
}
