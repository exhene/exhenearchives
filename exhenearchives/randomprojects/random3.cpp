#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int SAMPLES_PER_UPDATE = 1024;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Audio Visualizer");
    sf::Music music;

    if (!music.openFromFile("music.ogg"))
    {
        std::cerr << "Failed to open the music file." << std::endl;
        return 1;
    }

    music.play();

    sf::RectangleShape bars[SAMPLES_PER_UPDATE];
    for (int i = 0; i < SAMPLES_PER_UPDATE; ++i)
    {
        bars[i].setSize(sf::Vector2f(4, -100));
        bars[i].setPosition(WINDOW_WIDTH / SAMPLES_PER_UPDATE * i, WINDOW_HEIGHT / 2);
        bars[i].setFillColor(sf::Color::White);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        sf::SoundStream::Chunk chunk;
        music.getNextChunk(chunk);
        const sf::Int16* samples = chunk.samples;
        int sampleCount = chunk.sampleCount;

        int currentSample = 0;
        while (currentSample < sampleCount)
        {
            for (int i = 0; i < SAMPLES_PER_UPDATE && currentSample < sampleCount; ++i)
            {
                float sampleLevel = samples[currentSample++] / 32768.f;
                float barHeight = sampleLevel * (WINDOW_HEIGHT / 2);
                bars[i].setSize(sf::Vector2f(4, -barHeight));
                bars[i].setPosition(WINDOW_WIDTH / SAMPLES_PER_UPDATE * i, WINDOW_HEIGHT / 2 + barHeight / 2);
            }

            window.clear();
            for (int i = 0; i < SAMPLES_PER_UPDATE; ++i)
            {
                window.draw(bars[i]);
            }
            window.display();
        }
    }

    return 0;
}
