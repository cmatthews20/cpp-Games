void display(int BOARD_SIZE, char** board) {
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            char  p = board[i][j];
            std::string c(1, p);
            cout << "|\t" + c + "\t|\t";
        }
        cout <<  std::endl;
    }
}
