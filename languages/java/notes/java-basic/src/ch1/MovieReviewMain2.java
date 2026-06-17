package ch1;

public class MovieReviewMain2 {
    static void main() {
        MovieReview[] movieReviews = new MovieReview[2];
        movieReviews[0] = new MovieReview();
        movieReviews[1] = new MovieReview();

        movieReviews[0].review = "m1";
        movieReviews[0].title = "t1";
        movieReviews[1].review = "m2";
        movieReviews[1].title = "t2";

        for (MovieReview data : movieReviews) {
            System.out.println("영화 제목: " + data.title + " 영화 리뷰 : " + data.review);
        }
    }

}
