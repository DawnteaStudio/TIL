public class OverflowEx {
    public static void main(String[] args) {
        short sMin = -32768;
        short sMax = 32767;
        char cMin = 0;
        char cMax = 65535;

        System.out.println("sMin = " + sMin);
        // int 미만의 것들은 어떤 연산을 하더라도 결과 값은 항상 int형이 된다.
        //short + short = int      
        System.out.println("sMin-1 = " + (short)(sMin - 1));
        System.out.println("sMax = " + sMax);
        System.out.println("sMax + 1 = " + (short)(sMax + 1));
        System.out.println("cMin = " + (int)cMin);
        System.out.println("cMin - 1 = " + (int)--cMin);
        System.out.println("cMax = " + (int)cMax);
        System.out.println("cMax + 1 = " + (int)++cMax);
    }
}
