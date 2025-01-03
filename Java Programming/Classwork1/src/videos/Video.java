package videos;

import java.math.BigDecimal;
import java.time.LocalDate;

public class Video {
    private String name;// String is string
    private BigDecimal duration;
    private LocalDate uploadDate;
    private int likes;
    private static BigDecimal maxDuration;
    private final long id;

    public Video(long id){

        this.id = id;
    }
    public Video(String name, BigDecimal duration, int likes, long id) {
        this.name = name;
        this.duration = duration;
        this.likes = likes;
        this.id = id;
    }

    public String getName(){
        return name;
    }

    public BigDecimal getDuration() {
        return duration;
    }


    public static BigDecimal getMaxDuration(){
        return maxDuration;
    }

    public int getLikes() {
        return likes;
    }

    public static void setDuration(BigDecimal duration) {
        if(Video.getMaxDuration().compareTo(duration) < 0){
            duration = Video.getMaxDuration();
        }
        Video.maxDuration = maxDuration;
    }

    public boolean isFirstVideoLonger(Video video){
        if (this.getDuration().compareTo(video.getDuration()) > 0) {
            return true;
        }
        else {
            return false;
        }
    }

    public Video videoWithMoreLikes(Video video){
        if (this.getLikes() > video.getLikes()){
            return this;
        }
        else {
            return video;
        }
    }

    @Override
    public String toString() {
        return "Video{" +
                "name=" + name +
                "duration=" + duration +
                "likes=" + likes;
    }
}
