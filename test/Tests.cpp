#include <gtest/gtest.h>
#include "../code/klase.hpp"
#include "../code/libraries.hpp"

TEST(classTest, zmogusKlase)
{
    Studentas a("Kazys", "Rutuliukas");
    EXPECT_EQ("Kazys", a.getVardas());
    EXPECT_EQ("Rutuliukas", a.getPavarde());
}

TEST(bandymas, galutinisVid)
{
    Studentas a("Kazys", "Rutuliukas");
    vector<double> pazymiai = {8,9,10,6,8,10};
    a.galutinisPazymys(pazymiai, 10.0);

    EXPECT_EQ(9.4, a.getVidurkis());   
}

TEST(bandymas, galutinisMed)
{
    Studentas a("Kazys", "Rutuliukas");
    vector<double> pazymiai = {8,9,10,6,8,10};
    a.galutinisPazymys(pazymiai, 10.0);

    EXPECT_EQ(9.4, a.getMediana());   
}
