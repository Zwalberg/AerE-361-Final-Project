void counterdisplay(int current_count) {
  arcada.display->setCursor(80,200);
  arcada.display->println("Card Counter:");
  arcada.display->setCursor(140,220);
  arcada.display->println(current_count);
}

void windisplay() {
    arcada.displayBegin();
    arcada.setBacklight(255);
    arcada.display->fillScreen(ARCADA_WHITE);
    arcada.display->setTextColor(ARCADA_GREEN);
    arcada.display->setTextSize(6);
    arcada.display->setCursor(0,100);
    arcada.display->println("You Win!");      
}

void losedisplay() {
    arcada.displayBegin();
    arcada.setBacklight(255);
    arcada.display->fillScreen(ARCADA_WHITE);
    arcada.display->setTextColor(ARCADA_RED);
    arcada.display->setTextSize(6);
    arcada.display->setTextSize(5);
    arcada.display->setCursor(0,100);
    arcada.display->println("You Lose!");
}