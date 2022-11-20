use std::{
    any::{Any, TypeId},
    collections::HashMap,
};

use super::component::Component;

pub trait ComponentManagerT {
    fn as_any(&self) -> &dyn Any;
    fn as_mut_any(&mut self) -> &mut dyn Any;

    fn component_exists(&self, entity_id: usize) -> bool;
    fn remove(&mut self, entity_id: usize);
    fn get_type_id(&self) -> TypeId;
}

impl<T: 'static + Component> ComponentManagerT for ComponentManager<T> {
    fn as_any(&self) -> &dyn Any {
        self as &dyn Any
    }

    fn as_mut_any(&mut self) -> &mut dyn Any {
        self as &mut dyn Any
    }

    fn component_exists(&self, entity_id: usize) -> bool {
        cast_manager::<T>(self).component_exists(entity_id)
    }

    fn remove(&mut self, entity_id: usize) {
        cast_manager_mut::<T>(self).remove(entity_id);
    }

    fn get_type_id(&self) -> TypeId {
        TypeId::of::<T>()
    }
}

pub fn cast_manager<T: 'static + Component>(
    manager: &dyn ComponentManagerT,
) -> &ComponentManager<T> {
    manager
        .as_any()
        .downcast_ref::<ComponentManager<T>>()
        .unwrap()
}

pub fn cast_manager_mut<T: 'static + Component>(
    manager: &mut dyn ComponentManagerT,
) -> &mut ComponentManager<T> {
    manager
        .as_mut_any()
        .downcast_mut::<ComponentManager<T>>()
        .unwrap()
}

pub struct ComponentManager<T: Component> {
    components: Vec<T>,
    entity_ids: Vec<usize>,
    entity_id_map: HashMap<usize, usize>,
}

impl<T: Component> ComponentManager<T> {
    pub fn new() -> Self {
        ComponentManager {
            components: Vec::new(),
            entity_ids: Vec::new(),
            entity_id_map: HashMap::new(),
        }
    }

    pub fn component_exists(&self, entity_id: usize) -> bool {
        self.entity_id_map.contains_key(&entity_id)
    }

    pub fn add(&mut self, entity_id: usize, component: T) {
        if self.component_exists(entity_id) {
            error!("Failed to add component. Already taken.");
            return;
        }

        self.components.push(component);
        self.entity_ids.push(entity_id);

        self.entity_id_map
            .insert(entity_id, self.components.len() - 1);
    }

    pub fn remove(&mut self, entity_id: usize) {
        if !self.component_exists(entity_id) {
            error!("Failed to remove component. Does not exist.");
            return;
        }

        let index = *self.entity_id_map.get(&entity_id).unwrap();

        self.entity_id_map
            .insert(*self.entity_ids.last().unwrap(), index);
        self.components.swap_remove(index);
        self.entity_ids.swap_remove(index);
        self.entity_id_map.remove(&entity_id);
    }

    pub fn borrow_component(&self, entity_id: usize) -> Option<&T> {
        if !self.component_exists(entity_id) {
            error!("Can't borrow the component. It does not exist.");
            return None;
        }

        Some(&self.components[*self.entity_id_map.get(&entity_id).unwrap()])
    }

    pub fn borrow_component_mut(&mut self, entity_id: usize) -> Option<&mut T> {
        if !self.component_exists(entity_id) {
            error!("Can't borrow the component. It does not exist.");
            return None;
        }

        Some(&mut self.components[*self.entity_id_map.get(&entity_id).unwrap()])
    }

    pub fn borrow_entity_ids(&self) -> &Vec<usize> {
        &self.entity_ids
    }

    pub fn borrow_components(&self) -> &Vec<T> {
        &self.components
    }

    pub fn borrow_components_mut(&mut self) -> &mut Vec<T> {
        &mut self.components
    }
}
