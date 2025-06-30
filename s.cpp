#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
using namespace std;


class Video {

private:
    std::string  mVideoId;
    uint32_t mLikes, mDislikes, mViews;

public:

    Video(std::string VideoId, uint32_t Likes, uint32_t Dislikes, uint32_t Views) :
            mVideoId(VideoId), mLikes(Likes), mDislikes(Dislikes), mViews(Views) {}

    std::string getId() const { return  mVideoId;}
    uint32_t   getDislikes() const {return  mDislikes;}


    double getSimpleScore() const{
        double likes = (double) mLikes;
        double dislikes = (double) mDislikes;
        double views  = (double) mViews;
        return  (likes/dislikes) + 1 - (1/views);
    }

    virtual double getAdvancedScore() const = 0;
    void print(bool simple) const {
        cout << mVideoId << endl;
        if(simple) {
            cout << getSimpleScore() << endl;
        } else {
            cout << getAdvancedScore() <<endl;

        }
    }
   virtual ~Video() = default;
};


class  StudyVideo: public Video {
public:
    StudyVideo(const std::string& VideoId, uint32_t Likes, uint32_t Dislikes, uint32_t Views):
            Video(VideoId,Likes,Dislikes,Views) {}

    double getAdvancedScore() const override {
        return getSimpleScore()*2;
    }
};


class  AnimalVideo: public Video {
public:
    AnimalVideo(const std::string& VideoId, uint32_t Likes, uint32_t Dislikes, uint32_t Views):
            Video(VideoId,Likes,Dislikes,Views) {}

    double getAdvancedScore() const override {
        return getSimpleScore()*0.75;
    }
};


class SportsVideo: public Video {
public:
    SportsVideo(const std::string& VideoId, uint32_t Likes, uint32_t Dislikes, uint32_t Views):
            Video(VideoId,Likes,Dislikes,Views) {}

    double getAdvancedScore() const override {
        return getSimpleScore()*0.5;
    }
};


class VideoFactory: public Video{
public:
    static Video* createVideo(const std::string & id, const std::string& type, uint32_t likes, uint32_t dislikes, uint32_t views) {
        
        if (type == "Studiu") {
            return new StudyVideo(id,likes,dislikes,views);
        } else if (type == "Animale") {
            return new AnimalVideo(id,likes,dislikes,views);
        } else if (type == "Sport") {
            return new SportsVideo(id,likes,dislikes,views);
        } else {
            throw std::invalid_argument("EROARE");
        }
        
    }
};


bool comparator1(const Video* v1, const Video* v2) {
    return v1->getSimpleScore() < v2->getSimpleScore();
}

bool comparator2(Video*v1, Video*v2) {
    return v1->getAdvancedScore() < v2->getAdvancedScore();
}


int main() {


    uint64_t  n;
    char c;
    std::string ID,type;
    uint32_t likes, dislikes, views;

    cin >> n;
    std::vector <Video*> videos;
    for (int i = 0 ; i < n ; i++) {
        cin >> ID >> type >> views >> likes >> dislikes;
        if (type != "Studiu" && type != "Animale" && type != "Sport") {
            printf("EROARE");
            exit(0);
        }

        if (type == "Studiu") videos.push_back(new StudyVideo(ID,likes,dislikes,views));
        if (type == "Animale") videos.push_back(new AnimalVideo(ID,likes,dislikes,views));
        if (type == "Sport") videos.push_back(new SportsVideo(ID,likes,dislikes,views));

    }

    getchar();
    scanf("%c", &c);


    if (c == 'a') {
        for (int i = 0 ; i < videos.size() ; i++) {
            std::sort(videos.begin(), videos.end(), comparator1);
        }
            for (int i = 0 ; i < videos.size() ; i++) {
                cout << videos[i]->getId();
                printf(" %.2lf\n", videos[i]->getSimpleScore());
            }
        } else if (c == 'b') {
        double med = 0;
        for ( int i = 0 ; i < videos.size() ; i++ ) {
            med += videos[i]->getSimpleScore();
        }
        med /= videos.size();

        for ( int i = 0 ; i < videos.size() ; i++ ) {
            if (videos[i]->getSimpleScore() > med) {
                cout << videos[i]->getId();
                printf(" %.2lf\n", videos[i]-> getSimpleScore()) ;
            }
        }
    } else if ( c == 'd') {

        for (int i = 0 ; i < videos.size() ; i++) {
            std::sort(videos.begin(), videos.end(), comparator2);
        }
        for (int i = 0 ; i < videos.size() ; i++) {
            cout << videos[i]->getId();
            printf(" %.2lf\n", videos[i]->getAdvancedScore());
        }
    } else if (c == 'c') {
        int contor = 0;
        while ( cin >> ID >> type >> views >> likes >> dislikes ) {
                /*for (int i = 0 ; i < videos.size(); i++) {
                    if (ID != videos[i]->getId())  contor++;
                }

                if( contor != videos.size() ) {*/

            if (type == "Studiu") videos.push_back(new StudyVideo(ID,likes,dislikes,views));
            if (type == "Animale") videos.push_back(new AnimalVideo(ID,likes,dislikes,views));
            if (type == "Sport") videos.push_back(new SportsVideo(ID,likes,dislikes,views));

        }

        for (int i = 0 ; i < videos.size() ; i++) {
            std::sort(videos.begin(), videos.end(), comparator1);
        }
        for (int i = 0 ; i < videos.size() ; i++) {
            cout << videos[i]->getId();
            printf(" %.2lf\n", videos[i]->getSimpleScore());
        }
    }





    return 0;
}
