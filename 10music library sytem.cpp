#include <iostream>
#include <cstring>

using namespace std;

class mls {
    char *title, *artist, *album, *genre;
    float dur;
    int rel;

public:
    mls *prev, *next;

    mls() {
        title = artist = album = genre = nullptr;
        dur = 0.0;
        rel = 0;
        prev = next = nullptr;
    }

    void create() {
        title = new char[50];
        artist = new char[50];
        album = new char[50];
        genre = new char[50];

        cout << "enter title: ";
        cin.ignore();
        cin.getline(title, 50);

        cout << "enter artist: ";
        cin.getline(artist, 50);

        cout << "enter album: ";
        cin.getline(album, 50);

        cout << "enter genre: ";
        cin.getline(genre, 50);

        cout << "enter duration (in minutes): ";
        cin >> dur;

        cout << "enter release year: ";
        cin >> rel;
    }

    void add(mls *&start, mls *&end) {
        mls *newTrack = new mls;
        newTrack->create();

        if (start == nullptr) {
            start = end = newTrack;
        } else {
            end->next = newTrack;
            newTrack->prev = end;
            end = newTrack;
        }
    }

    void remove(mls *&start, mls *&end, const char *trackTitle) {
        if (start == nullptr) {
            cout << "no tracks in the library to remove.";
            return;
        }

        mls *temp = start;
        while (temp != nullptr) {
            if (strcmp(temp->title, trackTitle) == 0) {
                if (temp == start) {
                    start = temp->next;
                    if (start != nullptr) {
                        start->prev = nullptr;
                    }
                } else if (temp == end) {
                    end = temp->prev;
                    if (end != nullptr) {
                        end->next = nullptr;
                    }
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }

                delete[] temp->title;
                delete[] temp->artist;
                delete[] temp->album;
                delete[] temp->genre;
                delete temp;
                cout << "track removed successfully!";
                return;
            }
            temp = temp->next;
        }
        cout << "track not found!";
    }

    void update(mls *start, const char *trackTitle) {
        mls *temp = start;
        while (temp != nullptr) {
            if (strcmp(temp->title, trackTitle) == 0) {
                cout << "enter new details for the track:";
                temp->create();
                cout << "track updated successfully!";
                return;
            }
            temp = temp->next;
        }
        cout << "track not found!";
    }

    void search(mls *start, const char *trackTitle) {
        mls *temp = start;
        while (temp != nullptr) {
            if (strcmp(temp->title, trackTitle) == 0) {
                cout << "track found!";
                cout << "title: " << temp->title;
                cout << "artist: " << temp->artist;
                cout << "album: " << temp->album;
                cout << "genre: " << temp->genre;
                cout << "duration: " << temp->dur << " mins";
                cout << "release year: " << temp->rel;
                return;
            }
            temp = temp->next;
        }
        cout << "track not found!";
    }

    void display(mls *start) {
        if (start == nullptr) {
            cout << "no tracks in the library.";
            return;
        }

        mls *temp = start;
        while (temp != nullptr) {
            cout << "title: " << temp->title;
            cout << "artist: " << temp->artist;
            cout << "album: " << temp->album;
            cout << "genre: " << temp->genre;
            cout << "duration: " << temp->dur << " mins";
            cout << "release year: " << temp->rel;
            cout << "------------------------";
            temp = temp->next;
        }
    }

    void displayreverse(mls *end) {
        if (end == nullptr) {
            cout << "no tracks in the library.";
            return;
        }

        mls *temp = end;
        while (temp != nullptr) {
            cout << "title: " << temp->title;
            cout << "artist: " << temp->artist;
            cout << "album: " << temp->album;
            cout << "genre: " << temp->genre;
            cout << "duration: " << temp->dur << " mins";
            cout << "release year: " << temp->rel;
            cout << ".....";
            temp = temp->prev;
        }
    }
};

int main() {
    mls *start = nullptr, *end = nullptr;
    mls musicLibrary;

    int choice;
    do {
        cout << "music library system";
        cout << "1. add a track";
        cout << "2. remove a track";
        cout << "3. update a track";
        cout << "4. search a track";
        cout << "5. display all tracks";
        cout << "6. display all tracks in reverse order";
        cout << "7. exit";
        cout << "enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                musicLibrary.add(start, end);
                break;
            case 2: {
                char title[50];
                cout << "enter the title of the track to remove: ";
                cin.ignore();
                cin.getline(title, 50);
                musicLibrary.remove(start, end, title);
                break;
            }
            case 3: {
                char title[50];
                cout << "enter the title of the track to update: ";
                cin.ignore();
                cin.getline(title, 50);
                musicLibrary.update(start, title);
                break;
            }
            case 4: {
                char title[50];
                cout << "enter the title of the track to search: ";
                cin.ignore();
                cin.getline(title, 50);
                musicLibrary.search(start, title);
                break;
            }
            case 5:
                musicLibrary.display(start);
                break;
            case 6:
                musicLibrary.displayreverse(end);
                break;
            case 7:
                cout << "exiting program.";
                break;
            default:
                cout << "invalid choice! try again.";
        }
    } while (choice != 7);

    return 0;
}

