pub struct Entity {
    alive: bool,
}

impl Entity {
    pub fn new() -> Self {
        Entity { alive: true }
    }

    pub fn is_alive(&self) -> bool {
        self.alive
    }

    pub fn enable(&mut self) {
        self.alive = true;
    }

    pub fn disable(&mut self) {
        self.alive = false;
    }
}
