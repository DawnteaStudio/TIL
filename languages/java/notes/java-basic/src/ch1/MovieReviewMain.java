package ch1;

public class MovieReviewMain {
    static void main() {
        MovieReview mr = new MovieReview();
        mr.title = "bow";
        mr.review = "wow";

        System.out.println("영화 제목 : " + mr.title + " 영화 리뷰 : " + mr.review);
    }
}
