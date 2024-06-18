#define Ver2

export module basegeo;
export namespace basegeo {

    struct BasePoint{
        double x,y;
    };
}
export namespace basegeo {
#ifdef Ver2
    struct BasePoint2{
        double x,y;
    };
#endif
}